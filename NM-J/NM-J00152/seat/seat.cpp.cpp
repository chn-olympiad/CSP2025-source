#include<bits/stdc++.h>
using namespace std;
int n,m,a[15],R,t,e;
int cmp(int x,int y){
    return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    R=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(R==a[i]){
            t=i;
            break;
        }
    }
    for(int i=1;i<=m;i++){
    	if(e+n<t){
    		e+=n;
			continue;
		}
		else{
			if(i%2==1){
				cout<<i<<' '<<t-e;
			}
			else{
				cout<<i<<' '<<n-t+e+1;
			}
			return 0;
		}
	}
    return 0;
}
