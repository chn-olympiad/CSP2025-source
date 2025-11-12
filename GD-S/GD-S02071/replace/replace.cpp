#include<bits/stdc++.h>
using namespace std;
int n,q;
map<string,string>u;
string d(string h,int g,int k)
{
	string e="";
	for(int i=g;i<=k;i++)e+=h[i];
	return e;
}
void f(string a,string b)
{
	int num=0;
	for(int i=0;i<a.size()-1;i++)
	{
		if(d(a,0,i-1)==d(b,0,i-1))
		{
			string r1="",r2="";
			for(int j=i;j<a.size();j++)
			{
				r1+=a[j];
				r2+=b[j];
				if(u[r1]==r2&&d(a,j+1,a.size()-1)==d(b,j+1,b.size()-1))num++;
			}
		}
	}
	printf("%d\n",num); 
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout); 
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)
    {
    	string a,b;
    	cin>>a>>b;
    	u[a]=b;
	}
	for(int i=1;i<=q;i++)
	{
		string a,b;
		cin>>a>>b;
		f(a,b);
	}
	return 0;
} 
