#include<bits/stdc++.h>
using namespace std;
const int N=998244353;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(isdigit(c)){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return f*x;
}
long long ans;

int a[5005];
void dfs(int  x,int he,int max1,int l,int now){
	cout<<he<<endl;
	if(he<=2*max1&&now>l)return ;
	else if(he>2*max1&&now>l) {
		l++;
		ans=(ans+1)%N;
		return;
	}

}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	cout<<n-3+1<<endl;
}
