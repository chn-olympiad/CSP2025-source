#include<bits/stdc++.h>
using namespace std;
int a[500101];
struct i
{
	int l,r;
}b[500101];
bool cmp(i a,i b)
{
	return a.r<b.r;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,t=0,rr=0,e=0;
	cin>>n>>k;
	for(int c=1;c<=n;c++)
	{
		cin>>a[c];
		a[c]^=a[c-1];
	}
	for(int c=1;c<=n;c++) for(int d=c;d<=n;d++) if((a[c-1]^a[d])==k) b[++t].l=c,b[t].r=d;
	sort(b+1,b+t+1,cmp);
	for(int c=1;c<=t;c++) if(b[c].l>rr) e++,rr=b[c].r;
	cout<<e;
	return 0;
}
