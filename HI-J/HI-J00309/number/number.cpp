#include<bits/stdc++.h>
using namespace std;
bool cmp(int u,int b)
{
	return u>b;
}
string s;int a[1000005];long long sum=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
    	if(s[i]>='0'&&s[i]<='9' )
    	{	
		
    		a[sum]=s[i]-'0';
    	sum++;
		}
	}
	sort(a,a+sum,cmp);
	for(int i=0;i<sum;i++)
	{
		cout<<a[i];
	}

	return 0;
}

