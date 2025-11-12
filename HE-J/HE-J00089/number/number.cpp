#include<bits/stdc++.h>
using namespace std;
string s[10001];
int a,b,c,m,n;
int main()
{	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a>>b>>c>>m>>n;+
    if(a>b>c>m>n)
    {
    	cout<<a;
    }else{
	    if(b>c>m>n)
	    {
	    	cout<<b;
		}else{
			if(c>m>n)
			{
				cout<<c;
			}else{
				if(m>n){
					cout<<m;
				}else{
					cout<<n;
				}
			}
		}
    }
	return 0;
}
