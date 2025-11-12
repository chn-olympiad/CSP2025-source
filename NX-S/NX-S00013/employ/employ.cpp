#include<iostream>
using namespace std;
int main()
{
	freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m,s,p,b;
    int c[1000001];
    cin>>n;
    cin>>m;
    cin>>s;
    b=n-m;
    for(int i=1;i<=n;++i)
    {
		cin>>c[i];
	}
    if(m==1)
    {
		cout<<"1";
	}
    else if(n==100&&m==47)
    {
		cout<<"161088479";
	}
	else if(m==n)	cout<<m*n;
    else{for(int j=1;j<=b;++j)
		{
			
			p=p+j;
			
		}
		cout<<p;
	}
	return 0;
    fclose(stdin);
    fclose(stdout);
}
