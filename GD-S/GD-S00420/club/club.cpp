#include<bits/stdc++.h>
using namespace std;
const int N=1e6+6;
int t,n;
int a[N],b[N],c[N];
bool cmp(int x,int y){
	return x>y;
}
int main(){
    freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i],&b[i],&c[i]);
	    }
	    sort(a+1,a+1+n,cmp);
	    int ans=0;
	    for(int i=1;i<=n/2;i++){
	    	ans+=a[i];
		}
		printf("%d\n",ans); 
	}
   return 0;	
}
