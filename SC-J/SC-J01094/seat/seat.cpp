#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read(){
	ll x=0,w=1;
	char ch=0;
	while(ch<'0'||ch>'9'){
		if(ch=='-')w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*w;
}
inline void write(ll x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	static int sta[35];
	int top=0;
	do{
		sta[++top]=x%10;
		x/=10;
	}while(x);
	while(top)putchar('0'+sta[top--]);
}
int mp[105][105];
int n,m,all,a[1005],cnt,num;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	n=read();m=read();
	all=n*m;
	for(int i=1;i<=all;i++)a[i]=read();
	num=a[1];
	sort(a+1,a+all+1,[](int x,int y){return x>y;});
	for(int i=1;i<=m;i++){
		if(i&1){
			for(int j=1;j<=n;j++)mp[j][i]=++cnt;
		}else{
			for(int j=n;j;j--)mp[j][i]=++cnt;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[mp[i][j]]==num){
				cout<<j<<" "<<i<<"\n";
				return 0;
			}
		}
	}
	return 0;
}
/*
//freopen("seat.in","r",stdin);
//freopen("seat.out","w",stdout);
假装我注释了freopen，这样就能上迷惑行为大赏了（
freopen("set.out","w",stdout);
freopen("set.out","w",stdout);
freopen("saet.out","w",stdout);
freopen("saet.out","w",stdout);
假装我打错了freopen，这样就能上迷惑行为大赏了（
*/