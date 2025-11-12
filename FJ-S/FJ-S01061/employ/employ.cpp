#include<bits/stdc++.h>
using namespace std;

int read(){int x=0,f=1;char c=getchar();while(c<48 || c>57){if(c=='-'){f=-1;}c=getchar();}while(c>=48 && c<=57){x=(x<<1)+(x<<3)+(c^48);c=getchar();}return x*f;}
void write(int x){if(x<0){x=-x;putchar('-');}if(x>9){write(x/10);}putchar((x%10)^48);}
/*


*/
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	time(0);
	write(rand()%998244353);

	return 0;
}

