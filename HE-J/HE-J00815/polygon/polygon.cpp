#include<bits/stdc++.h>
using namespace std;
int n,ff;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=3;i<=n;i++){
		if(a[i-2]+a[i-1]+a[i]>2*(max(a[i-2],max(a[i-1],a[i])))){
			ff++;
		}
	}
	cout<<ff;
	return 0;
}
