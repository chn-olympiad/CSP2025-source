#include<bits/stdc++.h>
using namespace std;
const int N=105;
int a[N];
int f(int ans,int n,int m){
    int x=ans/n+1;
    if(x&1)return ans%n+1;
    else return n-ans%n;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x,a1;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
        scanf("%d",&x),a[i]=x;
        if(i==1)a1=x;
	}
	sort(a+1,a+1+n*m);
	reverse(a+1,a+1+n*m);
	int ans;
	for(int i=1;i<=n*m;i++)if(a[i]==a1){ans=i;break;}
	ans--;
	printf("%d %d\n",ans/n+1,f(ans,n,m));
	return 0;
}
