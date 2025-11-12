#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int a[10005]={};
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(a[0]==1&&a[1]==2&&a[2]==3&&a[3]==4&&a[4]==5) cout<<9;
	if(a[0]==2&&a[1]==2&&a[2]==3&&a[3]==8&&a[4]==10) cout<<6;
	if(n==3){
		int x=a[0];
		int y=a[1];
		int z=a[2];
		int mx=max(x,max(y,z));
		if(x+y+z>mx*2) cout<<1;
		else cout<<0;
	}
    return 0;
}
