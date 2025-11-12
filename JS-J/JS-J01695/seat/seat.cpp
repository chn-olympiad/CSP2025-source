#include<bits/stdc++.h>

using namespace std;

const int N = 10+5;
const int M = 10+5;

pair<int,int> a[N*M];
int n,m;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
		scanf("%d",&a[i].first),a[i].second=i;
	sort(a+1,a+n*m+1);
	reverse(a+1,a+n*m+1);
	int k=0;
	for(int i=1;i<=m;i++)
		if(i&1){
			for(int j=1;j<=n;j++)
				if(a[++k].second==1){
					printf("%d %d\n",i,j);
					return 0;
				}
		}else{
			for(int j=n;j>=1;j--)
				if(a[++k].second==1){
					printf("%d %d\n",i,j);
					return 0;
				}
		}
	
}