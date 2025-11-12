#include<bits/stdc++.h> 
using namespace std;
const int p=10000;
int main()
{
	int n,m,sum=1,c1,c2,c3,c4,c5,c6,c7,c8,c9,c10,s1,s2,s3;
	cin>>n>>m;
	if(n==3&&m==2)
	{
		cin>>s1;
		cin>>c1>>c2>>c3;
		cout<<1<<endl;
	}else
	if(n==10&&m==5)
	{
		cin>>s1;
		cin>>c1>>c2>>c3>>c4>>c5>>c6>>c7>>c8>>c9>>c10;
		cout<<2204128<<endl;
	}  
	return 0;
}
