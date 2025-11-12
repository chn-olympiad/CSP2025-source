#include<bits/stdc++.h>
using namespace std;
#define int long long
char A[1000005];
string s;
signed main()
{
//	freopen("number.in","r",stdin);
//	freopen("number.out","w",stdout);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n,m=1;
	cin>>s;
	n=s.size();
	for(int i=0;i<=n;i++)
	{
		if(s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'||s[i]=='0')
		{
			A[m]=s[i];
			m++;
		}
	}
	sort(A+1,A+m+1);
	for(int i=m;i>=1;i--)
	{
		cout<<A[i];
	}
	return 0;
}





/*
8:46
bushi
what this???
T1 is harder than T2 and T3 for me...

9:02
thanks for baoli
*/