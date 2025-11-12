#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int n;struct node{
	int x,p;
	bool operator < (const node& a)const{
		return x>a.x;
	}
};
int a[100005][3];
int z[100005];
int u[100005];
int w[100005];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;cin>>T;while(T--){
		cin>>n;int k=n/2;
		if(n==2&&false){
			int a1,a2,a3,b1,b2,b3;
			cin>>a1>>a2>>a3>>b1>>b2>>b3;
			int ans=-1;
			ans=max(ans,a1+b2);
			ans=max(ans,a1+b3);
			ans=max(ans,a2+b1);
			ans=max(ans,a2+b3);
			ans=max(ans,a3+b1);
			ans=max(ans,a3+b2);
			cout<<ans<<endl;
			continue; 
		}
		priority_queue<node> q;
		int ans=0,cnt[3]={0};bool check=false;
		for(int i=1;i<=n;i++){
			pair<int,int> tmp[3];
			cin>>tmp[0].first;tmp[0].second=0;a[i][0]=tmp[0].first;
			cin>>tmp[1].first;tmp[1].second=1;a[i][1]=tmp[1].first;
			cin>>tmp[2].first;tmp[2].second=2;a[i][2]=tmp[2].first;
			sort(tmp,tmp+3);z[i]=tmp[2].second;u[i]=tmp[1].second;
			w[i]=tmp[2].first-tmp[1].first;
			ans+=a[i][z[i]],cnt[z[i]]++;
			if(cnt[z[i]]>k){
				if(!check){
					check=true;
					for(int j=1;j<i;j++)
						if(z[i]==z[j]) q.push({w[j],j});
				}q.push({w[i],i});
				int y=q.top().p;
				ans-=q.top().x;
				q.pop();
				cnt[z[i]]--;
//				cout<<y<<'#';
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
