#include<bits/stdc++.h>
using namespace std;
int n,m,x;
int a[10005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}x=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			x=i;
		}
	}
	x=n*m-x+1;
	int t;
	if((x/n)*n==x) t=(x/n);
	else t=(x/n+1);
	cout<<t<<" ";
	if(t%2) cout<<((x%n)?(x%n):n);
	else cout<<m-((x%n)?(x%n):n)+1;
	return 0;
}
//2 3 1 2 3 4 5 6
