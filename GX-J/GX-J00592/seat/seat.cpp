#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    int i=0,n,m,a,max=0;
    cin>>n>>m;
    for(i=0;i<n*m;i++){
    	cin>>a;
    	if(a>=max){
    	max=a;
	    }
    }
    cout<<max;
}
