#include<bits/stdc++.h>
using namespace std;
string a;
int s[15],n;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	n=a.size();
	for(int i=0;i<n;i++)
		s[a[i]-48]++;
	for(int i=9;i>=0;i--)
		for(int j=s[i];j>0;j--)
			cout<<i;
	return 0;
}
