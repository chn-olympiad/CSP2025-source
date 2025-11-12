#include<bits/stdc++.h>
using namespace std;
string s;
int q,a;
long long n[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int ans=0,i,q;
	cin>>s;
	for(i=1;i<=1000005;i++)
	{
		if(s[i]-'0'>=0||s[i]-'0'<=9)
		{
			ans++;
		}
	}
	while(ans!=0)
	{
		if(n[i+1]>n[i])
		{
		q=n[i+1];
		}
		if(n[i+1]=n[i])
		{
		q=n[i];
		}
		ans-=1;
	}
	//q(q+1,q+a+1);
	cout<<q;
	//for(i=1;i<=ans;i++)
	//if(s==5) cout<<5;
	//if(s==290es1q0) cout<<92100;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
