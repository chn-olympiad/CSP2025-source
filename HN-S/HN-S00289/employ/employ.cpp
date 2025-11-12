#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,r=0;
	cin>>m;
	int s[n],c[n];
	cin>>s[n];
	for(int j=0;j<=n;j++){
		cin>>c[j];
	}
	for(int i=1;i<=n;i++){
		if(s[i]>c[i]){
			r=r+0;
		}else{
			r++;
		}
		for(int x=0;x<=n;x++){
			c[x]=c[n-1];
			if(x=n){
				c[x]=c[1];
			}
		}
	}
	cout<<r;
	return 0;
}
