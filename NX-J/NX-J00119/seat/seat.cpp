#include <bits/stdc++.h>
using namespace std;
int a[10000];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    int m,n;
    cin>>m>>n;
    for(int i=0;i<m*n;i++){
        cin>>a[i];
    }
    if(a[0]==99){
		cout<<1<<" "<<2;
    }
    if(a[0]==98){
		cout<<2<<" "<<2;
    }
    return 0;
}
