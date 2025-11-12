#include<bits/stdc++.h>
using namespace std()
int n,a[10005][10005],ans;
int main(){
freopen("replace.in","r",stdin);
freopen("replace.out","w",stdout);
cin>>n;
for(int i=1;i<=n;i++){
	for(int j=1;j<=i;j++){
		cin>>a[i][j];
	}
	}
	for(int i=1;i<=n;i++){
	for(int j=1;j<=i;j++){
		if(a[i][j]<=0||a[i][j]<=9){
			ans++;
			}
	}
}
	for(int i=1;i<=n;i++){
	for(int j=1;j<=i;j++){
	cout<<ans;	
	}
}
return 0;
}
