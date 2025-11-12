#include<bits/stdc++.h> 
using namespace std;
string s;
long long a[1100000],l=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long n=s.size();
	long long i;
	for(i=0;i<n;i++)
	{
		if(s[i]-'0'>=0&&s[i]-'0'<=9)
		{
			a[l]=s[i]-'0';
			l++;
			
		}
	}
	sort(a,a+l);
	for(i=l-1;i>=0;i--)
	cout<<a[i];
	return 0;
}
