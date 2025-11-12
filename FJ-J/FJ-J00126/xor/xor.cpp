#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+50;
int n,k,a[N],dp[N],ans,idx;
//dp[i]表示在1~i中最多能选的区间数
//dp数组具有单调不降性
int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-'){f=-1;}ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48),ch=getchar();}
	return x*f;
}
void write(int x){
	if(x<0){putchar('-');x=-x;}
	if(x<10){putchar(x+48);}
	else{write(x/10);putchar(x%10+48);}
	return;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read(),k=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++){
		int res=0;
		for(int j=i;j>idx;j--){
			res^=a[j];
			if(res==k){
				ans++;
				idx=i;
				break;
			}
		}
	}
	write(ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
