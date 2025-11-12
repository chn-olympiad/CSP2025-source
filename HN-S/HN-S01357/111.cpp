#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<cmath>
using namespace std;
using ll=long long;
#define File_IO 0
#define debug 0
int gcd(int a,int b)
{
	if(b)while((a%=b)&&(b%=a));
	return a+b;
}
void Ex_gcd(int a,int b,int &x,int &y)
{
	if(b==0)
	{
		x=1;
		y=0;
		//1a+0=gcd(a,0)
		return;
	}
	int y,x;
	Ex_gcd(b,a%b,y,x);
	y-=std::floor(a/b)*x;
	//b(x1)+(a-floor(a/b)*b)(y1)=gcd(a,b)
	//a(y1)+b(x1-floor(a/b)*y1)=gcd(a,b)
}
int main()
{
	#if File_IO
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
	int a,b;
	cin>>a>>b;
	cout<<gcd(a,b);
	return 0;
}
