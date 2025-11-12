#include<bits/stdc++.h>
using namespace std;
string s;
long long n,a[1000005],b=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("numbre.out","w",stdout);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++){
		if(int(s[i])>=49&&int(s[i])<=57){
			b++;
			a[b]=int(s[i])-48;
		}
	}
	sort(a+1,a+b+1);
	for(int i=b;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
