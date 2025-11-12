#include<bits/stdc++.h>
using namespace std;
int n,a[5022];
long long z;
void f(int x,int h,int d,int g){
	g++;
	h+=a[x];
	if(a[x]>d) d=a[x];
	if(g>=3 and h>2*d) z++;
	if(x==n) return;
	for(int i=x+1;i<=n;i++) f(i,h,d,g);
}
int main(){
//	freopen("polygon.in","r",stdin);
//	freopen("polygon,out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n-2;i++) f(i,0,0,0);
	cout<<z%998244353;
	return 0;
} 
