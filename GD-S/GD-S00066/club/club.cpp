#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,a[1000010],b[1000010],c[1000010],d[110],ans,x,y,z;
priority_queue<int> q,q2,q3; 
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;ans=0;x=0;y=0;z=0;
		memset(d,0,sizeof(d));
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]>=b[i]&&a[i]>=c[i]){
				d[1]++;ans+=a[i];
				if(b[i]>=c[i]){
					q.push(-a[i]+b[i]);
				}else{
					q.push(-a[i]+c[i]);
				}
			}else if(b[i]>=a[i]&&b[i]>=c[i]){
				d[2]++;ans+=b[i];
				if(a[i]>=c[i]){
					q2.push(-b[i]+a[i]);
				}else{
					q2.push(-b[i]+c[i]);
				}
			}else if(c[i]>=a[i]&&c[i]>=b[i]){
				d[3]++;ans+=c[i];
				if(a[i]>=b[i]){
					q3.push(-c[i]+a[i]);
				}else{
					q3.push(-c[i]+b[i]);
				}
			}
		}
		if(d[1]>n/2){
			for(int i=n/2+1;i<=d[1];i++){
				ans+=q.top();
				q.pop();x++;
			}
		}else if(d[2]>n/2){
			for(int i=n/2+1;i<=d[2];i++){
				ans+=q2.top();
				q2.pop();y++;
			}
		}else if(d[3]>n/2){
			for(int i=n/2+1;i<=d[3];i++){
				ans+=q3.top();
				q3.pop();z++;
			}
		}
		cout<<ans<<endl;
		for(int i=1;q.empty();i++){
			q.pop();
		}
		for(int i=1;q2.empty();i++){
			q2.pop();
		}
		for(int i=1;q3.empty();i++){
			q3.pop();
		}
	}
	return 0;
}
