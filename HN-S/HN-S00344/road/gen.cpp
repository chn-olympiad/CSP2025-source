#include<bits/stdc++.h>
int gi(){
	char c;int x=0,f=0;
	while(!isdigit(c=getchar()))f|=(c=='-');
	while(isdigit(c))x=(x*10)+(c^48),c=getchar();
	return f?-x:x;
}
std::mt19937 rnd(std::random_device{}());
#define pr std::pair<int,int>
#define all(x) (x).begin(),(x).end() 
#define mem(x,w) memest(x,w,sizeof(x)) 
#define sz(x) (int)((x).size()) 
#define fi first
#define se second 
template<class T>void cxk(T&a,T b){a=a>b?a:b;}
template<class T>void cnk(T&a,T b){a=a<b?a:b;}
int main(){
	freopen("road.in","w",stdout);
	int n=1000,m=10000,k=10,N=1e9;
	std::cout<<n<<' '<<m<<' '<<k<<'\n';
	for(int i=1;i<=m;i++){
		int u=rnd()%n+1,v=rnd()%n+1,w=rnd()%N;
		std::cout<<u<<' '<<v<<' '<<w<<'\n';
	}
	for(int i=1;i<=k;i++){
		int c=rnd()%N;std::cout<<c<<' ';
		for(int j=1;j<=n;j++)std::cout<<rnd()%N<<' ';
		puts("");
	}
	return 0;
}

