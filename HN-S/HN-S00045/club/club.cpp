#include<bits/stdc++.h>
using namespace std;
#define N 100010
#define i64 long long
inline void read(int& x){
	x=0;
	char ch=getchar();
	int f=1;
	while(!isdigit(ch)){
		if(ch=='-')f=~f+1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	x=f*x;
}
int n,T;
struct node{
	int pos,poss;
	i64 val,vall;
}a[N];
int num[10],vis[N];
i64 ans;
bool cmp(node x,node y){
//	if(x.val==y.val) return x.vall>y.vall;
//	else return x.val>y.val;
	return x.val-x.vall>y.val-y.vall;
}
void solve(){
	int i,j;
	ans=0;
	num[1]=num[2]=num[3]=0;
	read(n);
	for(i=1;i<=n;++i){
		a[i].val=a[i].vall=-1;
		for(j=1;j<=3;++j){
			int x;
			read(x);
			if(x>a[i].val){
				swap(a[i].val,a[i].vall);
				swap(a[i].pos,a[i].poss);
				a[i].val=x;
				a[i].pos=j;
			}else{
				if(x>a[i].vall){
					a[i].vall=x;
					a[i].poss=j;
				}
			}
		}
//		cout<<a[i].val<<" "<<a[i].vall<<" "<<a[i].pos<<" "<<a[i].poss<<endl;
	}
	sort(a+1,a+1+n,cmp);
	for(i=1;i<=n;++i){
		int pos=a[i].pos;
		if(num[pos]<n/2){
			ans+=a[i].val;
			num[pos]++;
		}else ans+=a[i].vall,num[a[i].poss]++;
	}
	printf("%lld\n",ans);
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int i,j;
	read(T);
	while(T--){
		solve();
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

