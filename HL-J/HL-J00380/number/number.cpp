#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >>s;
	int n=s.size(),i,j;
	for(i=0,j=0;i<n;i++)
	{
		if(s[i]-'0'<10){
			a[j]=int(s[i]-'0');
			j++;
		}
	}
	int max=0;
	sort(a,a+n);
	reverse(a,a+n);
	for(int m=0;m<j;m++)
	{
		cout<<a[m];
	}
	return 0;
}
