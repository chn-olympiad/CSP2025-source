#include<bits/stdc++.h>
using namespace std;
int n,a[105],ans=0;
bool cmp(int x,int y){
     return x<y;	
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1,cmp);
    if(a[1]+a[2]>a[3]) {
		 ans++;
	 }
    cout<<ans;
}
