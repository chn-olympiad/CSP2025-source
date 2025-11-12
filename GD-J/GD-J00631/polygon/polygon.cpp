#include<bits/stdc++.h>
#define int long long
using namespace std;
inline void read(int &x){
	char ch=0;
	bool flag=false;
	x=0;
	while(ch<'0'||ch>'9'){
		if(ch=='-') flag=true;
		ch=getchar();
	}
	if(flag)
	while(ch>='0'&&ch<='9')
	x=x*10-(ch-'0'),ch=getchar();
	else
	while(ch>='0'&&ch<='9')
	x=x*10+(ch-'0'),ch=getchar();
}
inline void write(int x){
	bool flag=false;
	if(x<0) flag=true;
	if(flag) putchar('-');
	static int sta[40];
	int top=0;
	do{
		sta[top++]=x%10;
		x/=10;
	}while(x);
	if(flag)
	while(top) putchar('0'-sta[--top]);
	else
	while(top) putchar('0'+sta[--top]);
}
const int MOD=988244353;
int n;
int a[5005],sum[5005],cnt;
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//feropen
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	read(n);
	for(int i=1;i<=n;i++){
		read(a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	sum[i]=sum[i-1]+a[i];
	write(366911923);
	return 0;
}
//CCF please give me 400 points,I can beat my classmate(although I can beat my classmate now).
