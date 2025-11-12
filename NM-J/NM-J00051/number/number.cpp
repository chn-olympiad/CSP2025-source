#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	int a;
	cin>>a;
	int b=a/1000000%10,c=a/100000%10,d=a/10000%10,e=a/1000%10,f=a/100%10,g=a/10%10,h=a%10;
	int i=max(b,max(c,max(d,max(e,max(f,max(g,h))))));
	int j=max(c,max(d,max(e,max(f,max(g,h)))));
	int k=max(d,max(e,max(f,max(g,h))));
	int l=max(e,max(f,max(g,h)));
	int m=max(f,max(g,h));
	int n=max(g,h);
	int o=max(i,max(j,max(k,max(l,max(m,n)))));
	int p=max(j,max(k,max(l,max(m,n))));
	int q=max(k,max(l,max(m,n)));
	int r=max(l,max(m,n));
	int s=max(m,n);
	cout<<o;
return 0;
}
