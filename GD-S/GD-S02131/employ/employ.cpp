#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define For(a,b,c) for(int a=b;a<=c;a++)
#define Fro(a,b,c) for(int a=b;a>=c;a--)
#define int long long
#ifdef __linux
#define gc getchar_unlocked
#define pc putchar_unlocked
#else
#define gc _getchar_nolock
#define pc _putchar_nolock
#endif
using namespace std;
using namespace __gnu_pbds;
const int N=505;
void read(int &i){
	char ch=gc();
	i=0;
	while((ch^32)&&(ch^10)){
		i=(i<<3)+(i<<1)+(ch-'0');
		ch=gc();
	}
}
int lst[N],k[N],res[N];
struct node{
	int c,id;
	bool operator<(const node&b)const{return (c==b.c)?(id<b.id):(c<b.c);}
}c[N];
int n,m,ans;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	bool f1=1;
	res[0]=1;
	For(i,1,N-1)
		res[i]=res[i-1]*i%998244353;
	cin>>n>>m;
	For(i,1,n){
		char ch;
		cin>>ch;
		k[i]=ch-'0';
		if(ch==0) f1=0;
	}
	For(i,1,n)
		cin>>c[i].c,c[i].id=i;
	sort(c+1,c+1+n);
//	if(f1){
//		int p=0,v=0;
//		For(i,1,n){
//			if(c[i].c)
//				p++;
//		}
//		v=res[p];
//		For(i,1,n){
//			if(c[i].c)
//				v-=res[c[i].c];
//		}
//		while(v<0) v+=998244353;
//		cout<<v;
//		return 0;
//	}
	int p;
	For(i,1,n){
		if(c[i].c)
			p++;
	}
	if(m==n){
		cout<<0;
		return 0;
	}
	if(p<m)return cout<<0,0;
	do{
		int cnt=0;
		lst[0]=0;
		For(i,1,n){
			if((k[i]==1)&&(lst[i-1]<c[i].c)){
				cnt++;
				lst[i]=0;
			}
			else lst[i]=lst[i-1]+1;
		}
//		For(i,1,n)
//			cout<<c[i].c<<"->"<<lst[i]<<" ";
//		cout<<'\n';	
		if(cnt>=m){
			ans++;
//			For(i,1,n)
//				cout<<c[i].c<<"->"<<lst[i]<<" ";
//			cout<<'\n';	
		}
		if(ans>=998244353) ans-=998244353;
	}while(next_permutation(c+1,c+1+n));
	cout<<ans;
	return 0;
}
