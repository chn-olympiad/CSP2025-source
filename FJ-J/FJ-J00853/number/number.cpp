#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    string n;
    long long m=1,a[100001];
	cin>>n;
	for(int i=0;i<n.size();i++)
		if(n[i]>='0'&&n[i]<='9')
		    a[m++]=n[i]-'0';
	sort(a+1,a+m);
	for(int i=m-1;i>=1;i--) cout<<a[i];
	return 0;
}
