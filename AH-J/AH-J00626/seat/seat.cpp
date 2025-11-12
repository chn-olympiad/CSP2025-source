#include<bits/stdc++.h>
using namespace std;
int n,m,a[1005],a1;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a1;
	a[1]=a1;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n*m,cmp);
	int p=1;
	for(int i=1;i<=n*m;i++){
		if(a[i]==a1)p=i;
	}
	cout<<(p-1)/n+1<<" ";
	if(((p-1)/n+1)%2==0)cout<<n-((p-1)%n);
	else cout<<1+((p-1)%n);
	return 0;
}
