#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],s,r;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	s=a[1];
	sort(a,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		if(a[i]==s){
			r=n*m-i+1;
			break;
		}
	}
	int l=(r+n-1)/n,h=r%n;
	if(!h)h=n;
	if(l%2==0)h=n-h+1;
	cout<<l<<' '<<h;
	return 0;
}
