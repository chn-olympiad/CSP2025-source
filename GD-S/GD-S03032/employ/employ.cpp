#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
char s;
int a[550],c[550];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s;
		a[i]=s-'0';
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]==0){
			a[i]=a[i-1]+1;
		} else{
			a[i]=a[i-1];
		}
	}
	for(int i=1;i<=n;i++){
		ans*=i;
	}
	cout<<ans;
	return 0;
}
/*
3 2
101
1 1 2
*/
