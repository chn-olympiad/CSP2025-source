#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
int a[maxn];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;scanf("%d %d",&n,&m);
	for(int i=1;i<=n*m;++i) scanf("%d",a+i);
	int k=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	int x=1,y=1,f=0;
	for(int i=1;i<=n*m;++i){
		if(a[i]==k) return printf("%d %d",y,x),0;
		if(f==0){
			if(x==n) ++y,f^=1;
			else ++x;
		}else{
			if(x==1) ++y,f^=1;
			else --x;
		}
	}
	return 0;
}
