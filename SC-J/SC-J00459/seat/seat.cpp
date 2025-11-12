#include<bits/stdc++.h>
using namespace std;
const int N=105;
int a[N];
bool cmp(int a,int b){
	return a>b;
}
int main() 
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	int k=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)if(a[i]==k){k=i;break;}
//	cout<<k<<'\n';
	int l=k/n+1;
	if(k%n==0)l--;
	cout<<l<<" ";
	int h=k%n;
	if(h==0)h=n;
	if(l%2==0)cout<<n-h+1;
	else cout<<h;
	return 0;
}

