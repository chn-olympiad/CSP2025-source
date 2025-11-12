#include<bits/stdc++.h>
using namespace std;
string s;
int z=0;
char a[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			z++;
			a[z]=s[i];
		}
	}
	sort(a+1,a+1+z);
	reverse(a+1,a+1+z);
	for(int i=1;i<=z;i++){
		cout<<a[i];
	}
	return 0;
}
