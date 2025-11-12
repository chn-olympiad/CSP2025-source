#include<bits/stdc++.h>
using namespace std;
char a;
int a0=0,a1=0,a2=0,a3=0,a4=0,a5=0,a6=0,a7=0,a8=0,a9=0,i;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    while(cin>>a)
    {
		if(a=='9')a9++;
		else if(a=='8')a8++;
		else if(a=='7')a7++;
		else if(a=='6')a6++;
		else if(a=='5')a5++;
		else if(a=='4')a4++;
		else if(a=='3')a3++;
		else if(a=='2')a2++;
		else if(a=='1')a1++;
		else if(a=='0')a0++;
    }
	for(i=1;i<=a9;i++)cout<<"9";
	for(i=1;i<=a8;i++)cout<<"8";
	for(i=1;i<=a7;i++)cout<<"7";
	for(i=1;i<=a6;i++)cout<<"6";
	for(i=1;i<=a5;i++)cout<<"5";
	for(i=1;i<=a4;i++)cout<<"4";
	for(i=1;i<=a3;i++)cout<<"3";
	for(i=1;i<=a2;i++)cout<<"2";
	for(i=1;i<=a1;i++)cout<<"1";
	for(i=1;i<=a0;i++)cout<<"0";	                                          
} 
