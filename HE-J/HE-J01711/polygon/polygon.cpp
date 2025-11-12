#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e3+10,mod=998244353;
template<typename T>void read(T&x){
	int f=1;x=0;char c;
	do{c=getchar();if(c=='-')f=-1;}while(!isdigit(c));
	do{x=x*10+c-'0';c=getchar();}while(isdigit(c));x=x*f;
}
int n,a[N],b[N],ans;
void dfs(int x,int y,int z){
	if(z>=x){
		int ma=-10,mi=0;
		for(int i=1;i<=n;i++){
			if(a[b[i]]>ma)ma=a[b[i]];
			mi+=a[b[i]];
		}
//		cout<<mi<<" "<<ma<<" ";
		if(mi>ma*2)ans=(ans+1)%mod;
//		cout<<"********";cout<<endl;
		return ;
	}
	for(int i=y+1;i<=n;i++){
		z++;
		b[z]=i;
		dfs(x,i,z);
		z--;
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	read(n);
	for(int i=1;i<=n;i++){
		read(a[i]);
	}
	for(int i=3;i<=n;i++){//changdu
		for(int j=1;j<=n;j++){//qidian
			b[1]=j;
			dfs(i,j,1);
		}
	}
	cout<<ans%mod;
	return 0;
}
/*
5
1 2 3 4 5*/
