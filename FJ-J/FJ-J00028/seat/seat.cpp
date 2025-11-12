#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int r=n*m;
	int f;
	cin>>f;
	int c=1;
	for(int i=2;i<=r;i++){
		cin>>a[i];
		if(a[i]>f)c++;
	}
	if(((c-1)/n)%2==0)cout<<((c-1)/n)+1<<" "<<(c-1)%n+1;
	else cout<<((c-1)/n)+1<<" "<<m-(c-1)%n;
	return 0;
}