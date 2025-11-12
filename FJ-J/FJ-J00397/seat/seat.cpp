#include <bits/stdc++.h>
using namespace std;
#define rt return
typedef long long ll;
const int N=200;
const int M=20;
int n,m,a[N];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++) scanf("%d",&a[i]);
	int r=a[1],x;
	sort(a+1,a+n*m+1,greater<int>());
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			x=i;
			break;
		}
	}
	int y=0;
	for(int i=1;i<=m;i++){
		if(i&1){
			for(int j=1;j<=n;j++){
				++y;
				if(y==x){
					printf("%d %d\n",i,j);
					rt 0;
				}
			}
		}else{
			for(int j=n;j>=1;j--){
				++y;
				if(y==x){
					printf("%d %d\n",i,j);
					rt 0;
				}
			}
		}
	}
	rt 0;	
} 
