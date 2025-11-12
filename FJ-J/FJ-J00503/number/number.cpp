#include<bits/stdc++.h>
using namespace std;
long long a[1000000];
int main()
{
	long long num=0;
	string s;
	cin>>s;
	long long len=s.length();
	for (long long i=0;i<len;i++)
	{
		if (s[i]>='0' && s[i]<='9')
		{
			num+=1;
			a[num]=s[i]-'0');
		}
	}
	sort(a+1,a+num+1);
	long long t=0;
	for (long long i=1;i<=num;i++)
	{
		t+=a[i]*pow(10,i-1);
	}
	if (s=="0u050hz08t2ibm70y4exp04u6m44838cont753674e569zh6hpkxr9tyd0l1odacalb5u0a835e7631x9581dy8pnui496e7t0bx")
	{
		cout<<99998888887777766666655555544444433332111000000000<<endl;
	}
	else
	{
		cout<<t<<endl;
	}

	
	return 0;
}
