#include<bits/stdc++.h>
using namespace std;
int q[11][11],w[122],e,c,r,t,y,n,m;
int main(){
	freopen("seat.in","in",stdin);
	freopen("seat.out","out",stdout);
    cin>>n>>m;
    cin>>e;
    w[1]=e;
    for(int i=2;i<=n*m;i++){
    	cin>>w[i];
	}
    for(int i=1;i<=n*m;i++){
    	for(int j=i+1;j<=n*m;j++){
    		if(w[i]<w[j])swap(w[i],w[j]);
		}
	}
    for(int i=1;i<=n*m;i++){
    	if(w[i]==e){
    		t=i;
    		break;
		}
	}
	if(t/n*n==t)y=t/n;
	else y=t/n+1;
	t%=m;
	if(y%2==1)cout<<y<<' '<<t;
	else cout<<y<<' '<<m-t+1;
    return 0;
}
