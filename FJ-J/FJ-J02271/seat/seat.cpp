#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef int Rd;

inline Rd read(){Rd xxx=0,yyy=1;char ch=getchar();
while(ch<'0'||ch>'9'){if(ch=='-')yyy*=-1;ch=getchar();}
while(ch>='0'&&ch<='9'){xxx=(xxx<<1)+(xxx<<3)+(ch^48);ch=getchar();}
return xxx*yyy;
}

const int maxn=105;
int n,m,x,y;
int a[maxn];

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	/*奇偶性、向上取整*/
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		a[i]=read();
	//in_it 
	int cnt=1;
	for(int i=2;i<=n*m;i++)
		if(a[1]<a[i])
			cnt++;
	//work_for_the_rank 
	x=(cnt+n-1)/n,//xsqz
	cnt=(cnt-1)%n+1,//mod
	y=(x&1?(cnt):(m-cnt+1));//jopd
	//slv
	cout<<x<<' '<<y;
	//put_it
	return 0;
}
/*
霁月光风，不盈于怀，像大树抖落落叶一样为自己做减法，不纠结一次或大或小的失败，
相信未来如星辰大海般璀璨，不再踌躇于自己的半亩方塘。 
*/

