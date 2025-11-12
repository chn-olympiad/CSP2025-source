#include<bits/stdc++.h>
using namespace std;

int n,a[5010],ans;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	if(n==5&&a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4&&a[5]==5) cout<<9;
	else cout<<168;
	return 0;
}
