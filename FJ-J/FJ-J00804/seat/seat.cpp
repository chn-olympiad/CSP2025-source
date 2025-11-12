#include <bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int x=0, f=1;
	char c=getchar();
	while(c>'9' || c<'0'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c<='9' && c>='0'){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*f;
}
int a[110];
bool cmp(int x, int y){
	return x>y;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n=read(), m=read();
	for(int i=1;i<=n*m;i++){
		a[i]=read();
	}
	int x=a[1], k=1;
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				if(a[k]==x){
					cout << i << " " << j;
					return 0;
				}
				k++;
			}
		}
		else{
			for(int j=m;j>=1;j--){
				if(a[k]==x){
					cout << i << " " << j;
					return 0;
				}
				k++;
			}
		}
	}
	return 0;
}
/*
2 2
98 99 100 97
*/
