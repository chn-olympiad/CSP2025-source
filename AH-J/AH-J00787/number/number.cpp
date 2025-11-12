#include<bits/stdc++.h>
using namespace std;
int a[20];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int b=100000,sum=0;
    int len=s.size();
    for(int i=0;i<len;i++)
    {
		int k=int(s[i]);
		if(k>=48 && k<=57)
		a[k-48]++;
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=a[i];j++)
		{
		    if(b==0&&i==0)break;
		    cout<<i;
		    sum++;
		    if(sum==1)b=i;
		}
	}
	
    return 0;
}
