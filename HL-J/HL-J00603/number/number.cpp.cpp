#include<bits/stdc++.h>
using namespace std;
const int N = 10000e5 + 3;
int a[N],n[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int k;
	string s ,n;
	cin>>s;
	if(s.size() == 1)
	{
		cout<<s;
		return 0;
	}
	
	for(int i=0; i<s.size(); i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			n[i]=s[i];
		}
	}
	for(int i=0; i<s.size(); i++)
	{
		for(int j=0; j<s.size();j++)
		{
			if(n[i]>=n[j])
			{
				k=n[i];
				n[i]=n[j];
				n[j]=k;
			}		
				
		}
	}
	for(int i=0; i<s.size();i++)
		cout<<n[i];
	return 0;
}