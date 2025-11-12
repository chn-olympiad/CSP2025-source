#include<bits/stdc++.h>
using namespace std;
int n;
int s[5000+10];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>s[i];
	}
	int ans=0;
	if(n>3){
		for(int i=3; i<=n; i++){
			int a=1,b=1;
			for(int j=1;j<=i; j++){
				a*=(n-j+1);
			} 
			for(int j=1; j<=i; j++){
				b*=j;
			}
			ans+=a/b;
		}
	}else{
		int num=0;
		int maxv=0;
		for(int i=1; i<=n; i++){
			num+=s[i];
			maxv=max(maxv,s[i]);
		}
		if(num>(2*maxv)){
			ans=1;
		}
	}
	cout<<ans;
	return 0;
}
