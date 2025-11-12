#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+7,inf=(1<<31)-1;

ll ans=0;
int mx[N][3];
int a[N],b[N],c[N];



bool cmp(int a,int b){
    return a>b;
}
//priority_queue< int  > q;


int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;  scanf("%d",&t);
    while(t--){
       int n; scanf("%d",&n);
       for(int i=1;i<=n;i++){
        scanf("%d%d%d",&a[i],&b[i],&c[i]);
        sort(a+1,a+1+n,cmp);
        //sort(b+1,b+1+n;cmp);
        //sort(c+1,c+1+n;cmp);
        }long long  ans=0;
        
        for(int i=1;i<=n/2;i++){    
			ans=ans+a[i];
        }
		printf("%lld",ans);
    }
	
    return 0;
}

