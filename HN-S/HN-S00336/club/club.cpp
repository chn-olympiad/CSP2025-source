#include <bits/stdc++.h>
using namespace std;
const int N=100050;
int T,n,a[N][3],bm1,bm2,bm3,ans;
struct node{
	int id,w;
};
bool operator <(node a,node b){
	return a.w>b.w;
}
priority_queue<node> q1,q2,q3;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		ans=0;
		cin>>n;
		bm1=bm2=bm3=0;
		while(q1.size()) q1.pop();
		while(q2.size()) q2.pop();
		while(q3.size()) q3.pop();
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		for(int i=1;i<=n;i++){
			int o=max(a[i][1],max(a[i][2],a[i][3]));
			if(o==a[i][1]){	
				ans+=a[i][1];
				bm1++;
				q1.push({i,a[i][1]-max(a[i][2],a[i][3])});
			}else if(o==a[i][2]){	
				ans+=a[i][2];
				bm2++;
				q2.push({i,a[i][2]-max(a[i][1],a[i][3])});
			}else if(o==a[i][3]){	
				ans+=a[i][3];
				bm3++;
				q3.push({i,a[i][3]-max(a[i][1],a[i][2])});
			}
		
	}	
		for(int i=1;i<=n;i++){
				if(bm1>n/2){
					node p=q1.top();
					q1.pop();	
					bm1--;
						ans-=a[p.id][1];
					if(a[p.id][2]>=a[p.id][3]){
						bm2++;
						ans+=a[p.id][2];
					}else{
						bm3++;
						ans+=a[p.id][3];
					}			
				}
				if(bm2>n/2){
					node p=q2.top();
					q2.pop();
						bm2--;
						ans-=a[p.id][2];
					if(a[p.id][1]>=a[p.id][3]){
						bm1++;
						ans+=a[p.id][1];
					}else{
						bm3++;
						ans+=a[p.id][3];
					}			
				}
				if(bm3>n/2){
					node p=q3.top();
					q3.pop();	
					bm3--;
						ans-=a[p.id][3];
					if(a[p.id][1]>=a[p.id][2]){
						bm1++;
						ans+=a[p.id][1];
					}else{
						bm2++;
						ans+=a[p.id][2];
					}			
				}
	}	
	
	cout<<ans<<"\n";
	}
	return 0;
}

