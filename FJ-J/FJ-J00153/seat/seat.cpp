#include<bits/stdc++.h>
using namespace std;
int a[505];
int n,m,k,t,pos,h,l;
bool cmp(int p,int q){
	return p>q;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	k=n*m;
	for(int i=1;i<=k;i++)
		cin>>a[i];
	t=a[1];
	sort(a+1,a+1+k,cmp);
	for(int i=1;i<=k;i++)
	  if(a[i]==t) pos=i;
	l=pos/n+1;h=pos%n;
	if(h==0){
		h=n;
		l--;
	}
	if(l%2==0) h=n-h+1;
	cout<<l<<" "<<h;
	return 0;
}
