#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main(){
	int n,m,c=1,r=1;
	cin>>n>>m;
	int w=n*m,s[w];
	cin>>s[w];
	for(int i=1;i<=w;i++)
	{
		if(s[1]<=s[i])
		{
		    r++;
        }
        if(r>m)
        {
        	c++;
        	r=m;
		}
		if(r<1)
		{
			c++;
			r=1;
		}
	}
	cout<<c<<" "<<r;
	return 0;
}
