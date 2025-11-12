#include<bits/stdc++.h>
using namespace std;
int emp(int x)
{
	if(x==2)  return 2;
	return emp(x-1)*x;
}
int main(){
	freopen("empty.in","r",stdin);
	freopen("empty.out","w",stdout);
    char b[1000];
    int n,m,a[1000],s=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
		cin>>b[i];
		if(b[i]==1){
		   s++;
		}
		
		
    }
    for(int i=1;i<=n;i++)
    {
		cin>>a[i];
    }
    
	
    if(n==m&&n==s)
    {
		cout<<emp(n);
	}
	else 
	{
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
}

