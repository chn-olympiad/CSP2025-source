#include<bits/stdc++.h>
using namespace std;
int x[100010],y[100010],z[100010];
int mx[100010];
int mx_1[100010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while(t--){
		int n;
		int a=0,b=0,c=0;
		cin>>n;
		int ans=0;
		for(int i=1;i<=n;i++){
			cin>>x[i]>>y[i]>>z[i];           	
		}
		for(int i=1;i<=n;i++){
			mx[i]=max(x[i],y[i]);
			mx[i]=max(mx[i],z[i]);
		}
		for(int i=1;i<=n;i++){
			if(mx[i]==x[i]){
				a++;
			}
			if(mx[i]==y[i]){
				b++;
			}
			if(mx[i]==z[i]){
				c++;
			}
		}
		//int d,e,f;
		for(int i=1;i<=n;i++){
			if(x[i]<mx[i]&&x[i]!=mx[i]){
				mx_1[i]=x[i];
			}
			if(y[i]<mx[i]&&y[i]!=mx[i]){
				mx_1[i]=y[i];
			}
			if(y[i]<mx[i]&&z[i]!=mx[i]){
				mx_1[i]=z[i];
			}
		}
		int cnm=n/2;
		if(a<=cnm&&b<=cnm&&c<=cnm){
			for(int i=1;i<=n;i++){
				ans+=mx[i];
			}
		}else{
			for(int i=0;i<=cnm;i++){
				ans+=mx[i];
			}
			for(int i=1;i<=n-cnm-1;i++){
				ans+=mx_1[i];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
