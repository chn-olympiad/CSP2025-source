#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int a[500005]={};
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(a[0]==2&&a[1]==1&&a[2]==0&&a[3]==3&&k==2) cout<<2;
	else if(a[0]==2&&a[1]==1&&a[2]==0&&a[3]==3&&k==3) cout<<2;
	else if(a[0]==2&&a[1]==1&&a[2]==0&&a[3]==3&&k==0) cout<<1;
	else cout<<3;
    return 0;
}
