#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[100],ans=0;
	cin>>n;
	for(int i=0;i<=n;i++){
		cin>>a[i];
		ans+=a[i];
	}
	if(n>=3&&ans>a[n-1]*2)return 0;
}
