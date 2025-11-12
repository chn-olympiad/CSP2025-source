#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a[100005],r,q =1;
    cin>>n>>m;
    for(int i;i<=n*m;i++){
    	cin>>a[i];
    	if (i == 0){
    		r = a[i];
		}
		if(r < a[i]){
			q += 1;
		}
	}
	if(q<m){
		cout<<"1"<<q;
	}
	if(q>m){
		if (q%m == 0){
			cout<<q/m<<"1";
		}
		if (q%m != 0 && q/m%2 == 1){
			cout<<q/m+1<<m-q%m+1;
		}
		if (q%m != 0 && q/m%2 == 0){
			cout<<q/m+1<<q%m;
		}
	}

}
