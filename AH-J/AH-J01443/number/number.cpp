#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,cnt,a[1000005];
string x;
bool cmp(int n,int m){
	return n>m;
}
signed main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	cin>>x;
	n=x.size();
	x=" "+x;
	for(int i=1; i<=n; i++)
		if(x[i]>='0' && x[i]<='9')
			a[++cnt]=x[i]-'0';
	sort(a+1,a+cnt+1,cmp);
	for(int i=1; i<=cnt; i++)
		cout<<a[i];
    return 0;
}
