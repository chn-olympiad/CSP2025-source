#include<bits/stdc++.h>
using namespace std;
int n,x[100000],y[100000],z[999999];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>x[i]>>y[i]>>z[i];
		}
		int ans=0;
		
		int a=0,b=0,c=0;
		for(int i=1;i<=n;i++){
			
			if(x[i]==(x[i],max(y[i],z[i]))&&a<=n/2){
				ans+=max(x[i],max(y[i],z[i]));
				a++;
			}
			
			else if(y[i]==(x[i],max(y[i],z[i]))&&b<=n/2){
				ans+=max(x[i],max(y[i],z[i]));
				b++;
			}
			else if(z[i]==(x[i],max(y[i],z[i]))&&c<=n/2){
				ans+=max(x[i],max(y[i],z[i]));
				c++;
			}
		}if(n==2){
			ans=max(x[1]+y[2],max(x[1]+z[2],max(y[1]+x[2],max(y[1]+z[2],max(z[1]+x[2],z[1]+y[2])))));
			cout<<ans<<endl;
			continue;
		}
	else cout<<ans<<endl;
	}
	return 0;
}
