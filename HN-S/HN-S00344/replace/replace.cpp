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
	freopen("replace.in","r",stdin),freopen("replace.out","w",stdout);
	std::ios::sync_with_stdio(0),std::cin.tie(0);
	int n,q;std::cin>>n>>q;
	while(q--)std::cout<<0<<'\n';
	return 0;
}

