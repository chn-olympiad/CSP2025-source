#include<bits/stdc++.h>
using namespace std;
string a;
int m,x[100005];
int main()
{
	freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++) if(a[i]>='0'&&a[i]<='9') x[++m]=a[i]-'0';
	sort(x+1,x+m+1);
	for(int i=m;i>=1;i--) cout<<x[i];
	return 0;
}
