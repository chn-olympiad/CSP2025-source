#include<bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int x,int y){
	return x>y;
} 
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int tmp=a[1];
	sort(a+1,a+1+n*m,cmp);
	int ans=0;
	for(int i=1;i<=n*m;i++){
		if(a[i]==tmp) ans=i;
	}
	int ansl=(ans-1)/n+1,ansh;
	if(ansl%2==0) ansh=n-(ans-1)%n;
	else ansh=(ans-1)%n+1;
	cout<<ansl<<" "<<ansh;
	return 0;
}
