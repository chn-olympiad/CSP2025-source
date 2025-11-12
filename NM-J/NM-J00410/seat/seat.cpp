#include<bits/stdc++.h>
using namespace std;
int a[100],n,m,cnt=1;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        if(a[i]>a[1]){
        	cnt++;
		}
    }
    if(n==1){
    	cout<<cnt<<' '<<1;
    	return 0;
	}
	int x;
    if(cnt%n==0){
    	x=cnt/n;
	}
	else{
		x=(cnt+n-(cnt%n))/n;
	}
    if(x%2==1){
    	cout<<x<<' '<<cnt-((x-1)*n);
	}
	else{
		cout<<x<<' '<<x*n-cnt+1;
	}
    return 0;
}
