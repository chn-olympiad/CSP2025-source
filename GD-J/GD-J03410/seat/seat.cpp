#include<bits/stdc++.h>
using namespace std;
int n,m,cnt,a[10005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;++i)
		scanf("%d",&a[i]);
	int op=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	for(int j=1;j<=m;++j){
		if(j%2==1){
			for(int i=1;i<=n;++i){
				++cnt;
				if(a[cnt]==op)
					return cout<<j<<" "<<i,0;
			}
		}else{
			for(int i=n;i>0;--i){
				++cnt;
				if(a[cnt]==op)
					return cout<<j<<' '<<i,0;
			}
		}
	}
	return 0;
}
