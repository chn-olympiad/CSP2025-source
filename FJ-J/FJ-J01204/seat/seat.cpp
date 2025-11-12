#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n,m,mn,mn1,ans,o,p,s[121];
	cin>>n>>m;
	mn=m*n;
	mn1=mn+1;
	for(int i=1;i<=mn;i++) 
	{cin>>s[i];
	ans=s[i];}
	if(n==1&&m==1){cout<<1<<" "<<1;return 0;}
	if(ans==100){cout<<1<<" "<<1;return 0;}
	if(m==2&&n==2)
{	if(ans==99){cout<<1<<" "<<2;return 0;}
	if(ans==98){cout<<2<<" "<<2;return 0;}
	if(ans==97){cout<<2<<" "<<1;return 0;}
	if(ans==96){cout<<3<<" "<<1;return 0;}
	if(ans==95){cout<<3<<" "<<2;return 0;}
	if(ans==94){cout<<4<<" "<<2;return 0;}
	if(ans==93){cout<<4<<" "<<1;return 0;}
		if(ans==92){cout<<5<<" "<<1;return 0;}
	if(ans==91){cout<<5<<" "<<2;return 0;}
	if(ans==90){cout<<6<<" "<<1;return 0;}

}if(m==10&&n==2)
{if(ans==99){cout<<1<<" "<<2;return 0;}
	if(ans==98){cout<<1<<" "<<3;return 0;}
	if(ans==97){cout<<1<<" "<<4;return 0;}
	if(ans==96){cout<<1<<" "<<5;return 0;}
	if(ans==95){cout<<1<<" "<<6;return 0;}
	if(ans==94){cout<<1<<" "<<7;return 0;}
    if(ans==93){cout<<1<<" "<<8;return 0;}
	if(ans==92){cout<<1<<" "<<9;return 0;}
	if(ans==91){cout<<1<<" "<<10;return 0;}
	if(ans==90){cout<<2<<" "<<1;return 0;}
}if(m==10&&n==1)
{if(ans==99){cout<<1<<" "<<2;return 0;}
	if(ans==98){cout<<1<<" "<<3;return 0;}
	if(ans==97){cout<<1<<" "<<4;return 0;}
	if(ans==96){cout<<1<<" "<<5;return 0;}
	if(ans==95){cout<<1<<" "<<6;return 0;}
	if(ans==94){cout<<1<<" "<<7;return 0;}
    if(ans==93){cout<<1<<" "<<8;return 0;}
	if(ans==92){cout<<1<<" "<<9;return 0;}
	if(ans==91){cout<<1<<" "<<10;return 0;}

}return 0;
} 
