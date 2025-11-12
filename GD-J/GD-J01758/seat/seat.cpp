#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,id[N],a[N];
inline bool cmp(int x,int y){return a[x]>a[y];}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++) scanf("%d",&a[i]),id[i]=i;
	sort(id+1,id+n*m+1,cmp);
	int pos=0;
	for(int i=1;i<=n*m;i++) if(id[i]==1) pos=i;
	for(int i=1;i<=m;i++){
		if(pos<=n){
			if(i&1) printf("%d %d",i,pos);
			else printf("%d %d",i,n-pos+1);
			return 0;
		}pos-=n;
	}
	return 0;
}
