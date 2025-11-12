#include <bits/stdc++.h>
using namespace std;
int a[110];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int R=a[1];
    for(int i=1;i<=n*m;i++){
    	for(int j=1;j<=n*m;j++){
    		if(a[i]>a[j]){
    			swap(a[i],a[j]);
			}
		}
	}
	int w;
	for(int i=i;i<=n*m;i++){
		if(a[i]==R){
			w=i;
			break;
		}
	}
	int c,r;
	if(w>n){
		c=w/n+1;
	}else if(w<=n){
		c=1;
	}
	if(m%2==0){
		r=n-(w%n);
	}
	else if(m%2==1){
		r=w%n;
	}
	cout<<c<<" "<<r;
    return 0;
}