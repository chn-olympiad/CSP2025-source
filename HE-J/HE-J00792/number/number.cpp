#include<bits/stdc++.h>
using namespace std;
string s;
int ans,i,a[1000001],j,m,n;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n = s.length();
	for(i = 0;i < n;i++){
		if(s[i] >= '0' && s[i] <= '9') 
		{
			a[++j] = s[i];
		}
	}
	m = j;
	sort(a + 1,a + m);
	for(i = m;i >= 0;i--){
		cout<<a[i] - '0';
	}
}
