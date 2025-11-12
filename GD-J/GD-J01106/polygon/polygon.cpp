#include<bits/stdc++.h>
using namespace std;
int a[1000001],n;
long long v=0;
void w(int c,int s,int x){
	if(x>=n+1){
		if(c>2*s){
			v++;
		}
		return;
	}
	w(c+a[x],max(s,a[x]),x+1);
	w(c,s,x+1);
	return;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int t=1;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		t=max(t,a[i]);
	}
	if(t==1){
		for(int i=1;i<=n;i++){
			t=t*2;
		}
		for(int i=1;i<=n;i++){
			t=t-i;
		}
		t--;
		cout<<t;
		return 0;
	}
	w(0,0,1);
	cout<<v%998244353;
	return 0;
}
