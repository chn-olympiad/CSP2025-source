#include<bits/stdc++.h>
using namespace std;
int n,m,a[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int g,k=n*m;
    for(int i=1;i<=k;i++) cin>>a[i];
    g=a[1];
    sort(a+1,a+k+1,cmp);
    for(int i=1;i<=k;i++){
    	if(a[i]==g){
    		g=i;
    		break;
		}
	}
	int x=g/n,y=g%n;
	if(y==0){
		if(x%2) cout<<x<<" "<<n;
		else cout<<x<<" "<<1;
	}else if(x%2) cout<<x+1<<" "<<n-y+1;
	else cout<<x+1<<" "<<y;
	return 0;
}
