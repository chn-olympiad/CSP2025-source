#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=150;
int arr[N][N],a[N],cnt;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,f;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&a[++cnt]);
		}
	}
	f=a[1];
	bool flag=0;
	sort(a+1,a+1+cnt);
	int c=1,r=1;
	for(int i=cnt;i>=1;i--){
		if(r==n+1)c++,flag=1,r=n;
		if(r==0)c++,flag=0,r=1;
		if(a[i]==f){
			printf("%d %d",c,r);
			return 0;
		}
		if(flag)r--;
		else r++;
	}
	return 0;
}