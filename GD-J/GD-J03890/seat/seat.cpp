#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[105],num,h=1,l=1;
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n*m;i++)scanf("%lld",&a[i]);
	num=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==num){
			printf("%lld %lld",l,h);
			return 0;
		}
		if(l%2==1 && h<n){
			h++;
		}else if(l%2==1 && h==n){
			l++;
		}else if(l%2==0 && h>1){
			h--;
		}else if(l%2==0 && h==1){
			l++;
		}
	}
	return 0;
} 
