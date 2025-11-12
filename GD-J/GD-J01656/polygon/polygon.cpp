#include<bits/stdc++.h>
using namespace std;
int n,a[5010],c,mx=-114514,cc=1;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]>mx){
			mx=a[i];
		}
		c+=a[i];
	}
	if(c>mx*2){
		cout<<1;
	}else{
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
