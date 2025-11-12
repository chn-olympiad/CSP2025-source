#include<bits/stdc++.h>
using namespace std;
int n,m,ans,a[200],l=1;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>a[i];
    ans=a[1];
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=n*m;i++){
    	if(ans==a[i]){
    		ans=i;
    		break;
		}
	}
	while(ans-n>0){
		l++;
		ans-=n;
	}
	if(l%2==1) cout<<l<<" "<<ans;
	else cout<<l<<" "<<(n-ans+1);
	return 0;
}
