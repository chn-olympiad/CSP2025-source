#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a,s;
	cin>>a;
	int i,l=a.size();
	for(i=0;i<l;++i){if(a[i]>='0'&&a[i]<='9') s+=a[i];}
	sort(s.begin(),s.end());
	reverse(s.begin(),s.end());
	cout<<s;
}
