#include<bits/stdc++.h>
using namespace std;
char s[1000010];
int a[1000010];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int f=0,sum=0;
    cin>>s;
    int l=strlen(s);  
    for(int i=0;i<l;i++)
    {
		
		if(s[i]==48||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9')
		{
			int t=s[i];
			t%=48;
			a[f]=t;
			
		    f++;
		}
	}
	sort(a,a+f);
	for(int i=0;i<f;i++)
    {
		sum*=10;
		sum=sum+a[f-i-1];
	}
	cout<<sum;
    return 0;
    }
