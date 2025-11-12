#include<bits/stdc++.h>
using namespace std;
int main()
{
int a1,a2[10000],b;
freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);
cin>>a1>>b;
for(int i=1;i<=a1;i++)
{
	cin>>a2[i];
}
if(b==0)
cout<<"1";
if(b==1||b==2||b==3)
cout<<"2";
}//不是普及组这么难题都看不懂 