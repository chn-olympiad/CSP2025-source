#include<bits/stdc++.h>
using namespace std;
int a[10010],b[10010],c[10010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    int t;
    cin>>t;
   int sum;
 while(t--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i]>>b[i]>>c[i];
        if(n==2){
           sort (a+1,a+n+1);
           sort (b+1,b+n+1);
           sort (c+1,c+n+1);
           sum=a[3]+b[3]+c[3]-min(a[3],min(b[3],c[3]));
           }

    }
       cout<<sum;
    return 0;
}
