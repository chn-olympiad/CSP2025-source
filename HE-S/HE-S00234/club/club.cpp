#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=2e5+10;
struct nod{int a,b,c;}s[N];
int A[N],B[N],C[N],len1,len2,len3;
bool cmp(int x,int y){return x<y;}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int T;cin>>T;
	while(T--){
		int n;cin>>n;
		len1=0;len2=0;len3=0;
		LL ans=0;
		for(int i=1;i<=n;i++){
			cin>>s[i].a>>s[i].b>>s[i].c;
			ans+=max({s[i].a,s[i].b,s[i].c});
			if(s[i].a>=s[i].b&&s[i].a>=s[i].c)A[++len1]=i;
			else if(s[i].b>=s[i].c&&s[i].b>=s[i].a)B[++len2]=i;
			else C[++len3]=i;
		}
		if(len1>n/2){
			for(int i=1;i<=len1;i++)A[i]=s[A[i]].a-max(s[A[i]].b,s[A[i]].c);
			sort(A+1,A+1+len1,cmp);
			for(int i=1;i<=len1-n/2;i++)ans-=A[i];
		}
		if(len2>n/2){
			for(int i=1;i<=len2;i++)B[i]=s[B[i]].b-max(s[B[i]].a,s[B[i]].c);
			sort(B+1,B+1+len2,cmp);
			for(int i=1;i<=len2-n/2;i++)ans-=B[i];
		}
		if(len3>n/2){
			for(int i=1;i<=len3;i++)C[i]=s[C[i]].c-max(s[C[i]].a,s[C[i]].b);
			sort(C+1,C+1+len3,cmp);
			for(int i=1;i<=len3-n/2;i++)ans-=C[i];
		}
		cout<<ans<<"\n"; 
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/
