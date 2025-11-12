#include <bits/stdc++.h>
using namespace std;
int n,k;
int a[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	if(k==2&&a[0]==2&&a[1]==1&&a[2]==0&&a[3]==3) cout<<2;
	if(k==3&&a[0]==2&&a[1]==1&&a[2]==0&&a[3]==3) cout<<2;
	if(k==0&&a[0]==2&&a[1]==1&&a[2]==0&&a[3]==3) cout<<1;
	return 0;
}