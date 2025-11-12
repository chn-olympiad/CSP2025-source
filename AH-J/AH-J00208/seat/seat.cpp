#include <bits/stdc++.h>
using namespace std;
const int MAXN=15;
bool cmp(int a,int b){
	return a>b;
}
int n,m,a[MAXN*MAXN];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int o=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==o){
			o=i;break;
		}
	}
	int l=(o-1)/n+1,s=o-(l-1)*n;
	if(l%2==0){
		s=n-s+1;
	}
	cout<<l<<' '<<s;
	return 0;
}
