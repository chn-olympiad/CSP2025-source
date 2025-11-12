#include<bits/stdc++.h>
using namespace std;
int n,m,a[150],tmp,t,h,l;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
			cin>>a[i];
	tmp=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==tmp)
			t=i;	
	}
	l=t/n;
	h=t%n;
	if(h==0){
		if(l%2==0)
			cout<<l<<" "<<"1"<<'\n';
		else cout<<l<<" "<<m<<'\n';
		return 0;
	}
	l+=1;
	if(l%2==0)
		h=n-h+1;
	cout<<l<<" "<<h<<'\n';
	return 0;
}