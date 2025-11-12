#include<bits/stdc++.h>
using namespace std;
string s;
long long p0=0,p1=0,p2=0,p3=0,p4=0,p5=0,p6=0,p7=0,p8=0,p9=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='0') p0++;
		else if(s[i]=='1') p1++;
		else if(s[i]=='2') p2++;
		else if(s[i]=='3') p3++;
		else if(s[i]=='4') p4++;
		else if(s[i]=='5') p5++;
		else if(s[i]=='6') p6++;
		else if(s[i]=='7') p7++;
		else if(s[i]=='8') p8++;
		else if(s[i]=='9') p9++;
	}
	for(int i=0;i<p9;i++) cout<<"9";
	for(int i=0;i<p8;i++) cout<<"8";
	for(int i=0;i<p7;i++) cout<<"7";
	for(int i=0;i<p6;i++) cout<<"6";
	for(int i=0;i<p5;i++) cout<<"5";
	for(int i=0;i<p4;i++) cout<<"4";
	for(int i=0;i<p3;i++) cout<<"3";
	for(int i=0;i<p2;i++) cout<<"2";
	for(int i=0;i<p1;i++) cout<<"1";
	for(int i=0;i<p0;i++) cout<<"0";
	return 0;
}
