#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n;
int a[4];
int num[4];
int sz[4];
priority_queue<int,vector<int>,greater<int> > q1,q2,q3;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		memset(sz,0,sizeof(sz));
		int ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[1]>>a[2]>>a[3];
			num[1]=a[1],num[2]=a[2],num[3]=a[3];
			sort(a+1,a+1+3);
			int d=a[3]-a[2];
			for(int j=1;j<=3;j++){
				if(a[3]==num[j]){
					sz[j]++;
					if(j==1){
						q1.push(d);
					}else if(j==2){
						q2.push(d);
					}else if(j==3){
						q3.push(d);
					}
				}
			}
			ans+=a[3];
		}
		for(int i=1;i<=3;i++) {
			if(sz[i]>(n/2)){
				for(int j=1;j<=sz[i]-(n/2);j++){
					if(i==1){
						ans-=q1.top();
						q1.pop();
					}else if(i==2){
						ans-=q2.top();
						q2.pop();
					}else if(i==3){
						ans-=q3.top();
						q3.pop();
					}
				}
				break;
			}	
		}
		while(!q1.empty()) q1.pop();
		while(!q2.empty()) q2.pop();
		while(!q3.empty()) q3.pop();
		cout<<ans<<endl;
	}
}
