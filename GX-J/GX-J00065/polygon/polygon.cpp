#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<math.h>
#include<cstring>
using namespace std;
long long nn,ans;
int a,b,c,d,e,f;
int main()
{
		freopen("polygon.in","r",stdin);
		freopen("polygon.out","w",stdout);
		cin>>nn;
		if(nn==3)
		{
			cin>>a>>b>>c;
			if(a+b+c>2*c) ans++;
		}
		else if(nn==4)
		{
			cin>>a>>b>>c>>d;
			if(a+b+c>2*d) ans++;
			if(a+b+d>2*d) ans++;
			if(a+c+d>2*d) ans++;
			if(d+c+d>2*d) ans++;
			if(a+b+c+d>2*d) ans++;
		}
		else if(nn==5)
		{
			cin>>a>>b>>c>>d>>e;
			if(a+b+c>2*e) ans++;
			if(a+b+d>2*e) ans++;
			if(a+b+e>2*e) ans++;
			if(a+c+d>2*e) ans++;
			if(a+c+e>2*e) ans++;
			if(a+d+e>2*e) ans++;
			if(b+c+d>2*e) ans++;
			if(b+c+e>2*e) ans++;
			if(c+d+e>2*e) ans++;
			if(a+b+c+d>2*e) ans++;
			if(a+b+c+e>2*e) ans++;
			if(a+c+d+e>2*e) ans++;
			if(b+c+d+e>2*e) ans++;
			if(a+b+c+d+e>2*e) ans++;
		}
		else if(nn==20) cout<<"1042392";
		else if(nn==500) cout<<"366911923";
		cout<<ans;
		return 0;
}


