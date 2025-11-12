#include<bits/stdc++.h>
using namespace std;
const int N=114;
int n,m,a[N],k;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
		if(a[i]>a[1])k++;
	}
	for(int i=1,cnt=0,j;i<=m;i++){
		if(i&1){
			for(j=1;j<=n&&cnt<k;j++,cnt++);
			if(cnt==k){
				if(j<=n)printf("%d %d\n",i,j);
				else printf("%d %d\n",i+1,n);
				return 0;
			}
		}else{
			for(j=n;j>=1&&cnt<k;j--,cnt++);
			if(cnt==k){
				if(j>=1)printf("%d %d\n",i,j);
				else printf("%d %d\n",i+1,1);
				return 0;
			}
		}
	}
	return 0;
}