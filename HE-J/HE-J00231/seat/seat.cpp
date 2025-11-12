#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int f=1;
	int n=0;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(isdigit(c)){
		n=(n<<3)+(n<<1)+(c^48);
		c=getchar();
	}
	return n*f;
}
bool cmp(int a,int b){
	return a > b;
}
const int N=2e5+50;
int n,m,s[N];
int32_t main(){
	
	freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	
    n=read();
    m=read();
    int a=n*m;
    for(int i=1;i<=a;i++) s[i]=read();
    int g=s[1];
    int f;
    int sum=0;
    sort(s+1,s+a+1,cmp);
    for(int i=1;i<=a;i++){
    	sum++;
    	if(s[i]==g)	break;
	}
	int c;
	c=sum/n;
	if(sum%n!=0) c++;
	int r;
	if(c%2!=0) r=sum-(c-1)*n;
	else r=n-(sum-(c-1)*n)+1;
	printf("%lld %lld\n",c,r);
	return 0;
}

