#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int T,n,cnt[4],a[N][4],cho[N],ans;
struct qp{
	int val,id;
	bool operator<(const qp &q)const {
		return val<q.val;
	}
};
priority_queue<qp> q[4][4];
void solve(){
	cin>>n;ans=0;cnt[1]=cnt[2]=cnt[3]=0;
	for(int i=1;i<=3;i++)for(int o=1;o<=3;o++)if(i^o)while(!q[i][o].empty())q[i][o].pop();
	for(int i=1;i<=n;i++){
		int maxi,maxn=-1;
		for(int o=1;o<=3;o++){
			cin>>a[i][o];
			if(a[i][o]>maxn)maxn=a[i][o],maxi=o;
		}
		cho[i]=maxi;ans+=maxn;cnt[maxi]++;
		q[maxi][maxi%3+1].push((qp){a[i][maxi%3+1]-maxn,i});
		q[maxi][(maxi+1)%3+1].push((qp){a[i][(maxi+1)%3+1]-maxn,i});
		if(cnt[maxi]>n/2){
			if(cnt[(maxi+1)%3+1]==n/2||q[maxi][(maxi+1)%3+1].empty()||q[maxi][maxi%3+1].top().val>q[maxi][(maxi+1)%3+1].top().val){
				qp k=q[maxi][maxi%3+1].top();
				q[maxi][maxi%3+1].pop();
				if(cho[k.id]!=maxi)cout<<"???"<<endl;
				cho[k.id]=maxi%3+1;
				ans+=k.val;
				cnt[maxi%3+1]++;
				cnt[maxi]--;			
				q[cho[k.id]][cho[k.id]%3+1].push((qp){a[k.id][cho[k.id]%3+1]-a[k.id][cho[k.id]],k.id});
				q[cho[k.id]][(cho[k.id]+1)%3+1].push((qp){a[k.id][(cho[k.id]+1)%3+1]-a[k.id][cho[k.id]],k.id});	
				while(!q[maxi][maxi%3+1].empty()&&cho[q[maxi][maxi%3+1].top().id]!=maxi)q[maxi][maxi%3+1].pop();
				while(!q[maxi][(maxi+1)%3+1].empty()&&cho[q[maxi][(maxi+1)%3+1].top().id]!=maxi)q[maxi][(maxi+1)%3+1].pop();
			}
			else{
				qp k=q[maxi][(maxi+1)%3+1].top();
				q[maxi][(maxi+1)%3+1].pop();
				if(cho[k.id]!=maxi)cout<<"???"<<endl;
				cho[k.id]=(maxi+1)%3+1;
				ans+=k.val;
				cnt[(maxi+1)%3+1]++;
				cnt[maxi]--;
				q[cho[k.id]][cho[k.id]%3+1].push((qp){a[k.id][cho[k.id]%3+1]-a[k.id][cho[k.id]],k.id});
				q[cho[k.id]][(cho[k.id]+1)%3+1].push((qp){a[k.id][(cho[k.id]+1)%3+1]-a[k.id][cho[k.id]],k.id});
				while(!q[maxi][(maxi+1)%3+1].empty()&&cho[q[maxi][(maxi+1)%3+1].top().id]!=maxi)q[maxi][(maxi+1)%3+1].pop();
				while(!q[maxi][maxi%3+1].empty()&&cho[q[maxi][maxi%3+1].top().id]!=maxi)q[maxi][(maxi+1)%3+1].pop();
			} 
		}
	}
//	cnt[1]=cnt[2]=cnt[3]=0;
	cout<<ans<<endl;
//	ans=0;
//	for(int i=1;i<=n;i++)
//		ans+=a[i][cho[i]],cnt[cho[i]]++;
////	for(int i=1;i<=3;i++)cout<<cnt[i]<<' ';
//	cout<<ans<<endl; 
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
} 
