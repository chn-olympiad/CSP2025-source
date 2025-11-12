#include<bits/stdc++.h>
using namespace std;
int n,a,b,c,d[5000],x;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x;
		d[x]++;
	}
	for(int i=1;i<=n;i++){
		if(d[i]!=0){
			a=d[i];
			c=i;
			break;
		}
	}
	for(int i=c;i<=n;i++){
		if(d[i]!=0){
			b=d[i];
			c=i;
			break;
		}
	}
	for(int i=c;i<=n;i++){
		if(d[i]!=0){
			c=d[i];
			break;
		}
	}
	if(a+b>c&&a+c>b&&b+c>a){
		ans++;
	}
	cout<<ans;
	return 0;
}