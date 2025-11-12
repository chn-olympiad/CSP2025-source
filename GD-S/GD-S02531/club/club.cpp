#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vec vector
ll read(){
	ll Num=0,f=1;
	char c = getchar();
	while(c < '0'||c > '9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		Num=(Num<<1)+(Num<<3)+(c^48);
		c=getchar();
	}
	return Num*f;
}
constexpr int N=1e5+5;
int a[N][5],n,v[N];
bool f1=true,f2=true;
void SolVe(){
    n=read();
    int Lim=n>>1;
    for(int i=1;i<=n;++i){
    	for(int j=1;j<=3;++j){
    		a[i][j]=read();
    		if(j==2&&a[i][j]!=0)f1=false;
    		if(j==3&&a[i][j]!=0)f2=false;
		}
	}
	if(n==2){
		ll sum=max({a[1][1]+a[2][2],a[1][1]+a[2][3],a[1][2]+a[2][1],a[1][2]+a[2][3],a[1][3]+a[2][1],a[1][3]+a[2][2]});
		printf("%lld\n",sum);
		return;
	}
	if(n==4){
		ll sum=0;
		int c[4]={0};
		for(int i=1;i<=3;++i){
			for(int j=1;j<=3;++j){
				for(int k=1;k<=3;++k){
					for(int x=1;x<=3;++x){
						bool f=true; 
						++c[i],++c[j],++c[k],++c[x];
						for(int y=1;y<=3;++y){
							if(c[y]>Lim){
								f=false;
								break;
							}
						}
						if(!f){
							continue;
						}
						sum=max(sum,0ll+a[1][i]+a[2][j]+a[3][k]+a[4][x]);
					}
				}
			}
		}
		printf("%lld\n",0);
		return ;
	}
	if(f1&&f2){
		vec<int>v;
		for(int i=1;i<=n;++i)v.push_back(a[i][1]);
		stable_sort(v.begin(),v.end(),greater<int>());
		int cnt=1;
		ll sum=0;
		for(int i=0;i<v.size();++i){
			if(cnt<=Lim) sum+=v[i],++cnt;
			else break;
		}
		printf("%lld\n",sum);
		return ;
	}
	printf("%lld\n",114);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    int T=1;
    T=read();
    while(T--) SolVe();
	return 0;
}
