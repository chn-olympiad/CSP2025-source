#include<bits/stdc++.h>
using namespace std;
int a[5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ma=a[1];
	for(int i=1;i<=n;i++){
		ma=max(ma,a[i]);
	}
		
	return 0;
}
