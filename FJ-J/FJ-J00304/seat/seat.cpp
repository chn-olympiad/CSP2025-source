#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005],id;
bool cmp(int l,int r){
	return l>r;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	cin>>a[i];
	int t=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	if(a[i]==t)
	id=i;
	int s1,s2;
	s1=id%n;
	s2=id/n;
	if(s2%2==0)
	cout<<s2+(s1==0?0:1)<<" "<<(s1==0?1:s1);
	else cout<<s2+(s1==0?0:1)<<" "<<(s1==0?n:n-s1+1);
}
