#include<bits/stdc++.h>
using namespace std;
#define int long long 

int n,m;
int a[110];
int cnt=1;

signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
    	cin>>a[i];
    	if(a[i]>a[1])cnt++;
    }
    int x=(cnt+n-1)/n,y;
    if(x%2==1){
    	if(cnt%n==0){
    		y=n;
    	}else{
    		y=cnt%n;
    	}
    }else{
    	if(cnt%n==0){
    		y=1;
    	}else{
    		y=n-(cnt%n)+1;
    	}
    }
    cout<<x<<" "<<y;
	return 0;
} 
