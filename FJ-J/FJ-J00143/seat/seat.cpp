#include<bits/stdc++.h>
using namespace std;
int n,m;
struct _nm{
	int i,n;
}nm[105];
bool cmp(_nm u,_nm v){
	return u.n>v.n;
}
int si=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&nm[i].n);
		nm[i].i=i;
	}sort(nm+1,nm+1+n*m,cmp);
	while(nm[++si].i!=1);
	for(int i=1,sj=0;i<=m;i++){
		if(i%2){
			for(int j=1;j<=n;j++){
				sj++;
				if(sj==si){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}else{
			for(int j=n;j>=1;j--){
				sj++;
				if(sj==si){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}

