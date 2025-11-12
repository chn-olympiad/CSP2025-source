#include <bits/stdc++.h>
#define ll long long 
#define ld long double
#define ull unsigned long long
#define max3(a,b,c) max(a,max(b,c))
#define fi first
#define se second

using namespace std;
const int N=1e5+5;
struct node{
	int a,b,c,cz;
}g[N];
bool cmp(node x,node y){
	return x.cz>y.cz;
}
int mid3(int x,int y,int z){
	if(max3(x,y,z)==x) return max(y,z);
	if(max3(x,y,z)==y) return max(x,z);
	if(max3(x,y,z)==z) return max(x,y);
}
inline int in(){
	int s=0,w=1;char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') w=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		s=s*10+c-'0'; c=getchar();
	}return s*w;
}
int t,n;
int main(){
	std::ios::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0);
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>g[i].a>>g[i].b>>g[i].c;
			g[i].cz=max3(g[i].a,g[i].b,g[i].c)-mid3(g[i].a,g[i].b,g[i].c);
		}
		sort(g+1,g+1+n,cmp);
		int sum1=0,sum2=0,sum3=0;
		ll ans=0;
		for(int i=1;i<=n;i++){
			int a=g[i].a,b=g[i].b,c=g[i].c;
			int maxz=max3(a,b,c);
			if(maxz==a){
				if(sum1<(n/2)){
					sum1++; ans+=maxz;
				}
				else{
					if(b>c) ans+=b,sum2++;
					else ans+=c,sum3++;
				}
			}
			else if(maxz==b){
				if(sum2<(n/2)){
					sum2++; ans+=maxz;
				}
				else{
					if(a>c) ans+=a,sum1++;
					else ans+=c,sum3++;
				}
			}
			else{
				if(sum3<(n/2)){
					sum3++; ans+=maxz;
				}
				else{
					if(a>b) ans+=a,sum1++;
					else ans+=b,sum2++;
				}
			}
			//cout<<ans<<' ';
		}
		cout<<ans<<"\n";
	}
	return 0;
}
Ren5Jie4Di4Ling5%
4 3 1
1 2 2
2 3 3
3 4 4
0 1 8 9 2
ans 

4 3 3
1 2 2
2 3 3
3 4 4
0 9 9 9 9
0 8 8 8 8
0 7 7 7 7
ans 9

4 3 1
1 2 2
2 3 3
3 4 4
0 1 1 1 1
ans 4
