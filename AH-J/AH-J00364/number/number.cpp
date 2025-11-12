#include <bits/stdc++.h>
using namespace std;
long long a[1000010];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
    long long wz=0;
    cin>>s;
    long long len=s.size();
    for(long long i=0;i<len;i++)
    {
		if(s[i]>='0'&&s[i]<='9') 
		{
			wz++;
			a[wz]=s[i]-'0';
		}
	}
	sort(a+1,a+wz+1);
	if(a[wz]==0)
	{
		cout<<0<<endl;
		return 0;
	}
	for(long long i=wz;i>=1;i--) cout<<a[i];
    return 0;
}
//rp++
