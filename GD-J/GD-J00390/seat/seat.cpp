#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    int n,m;
    int b=0;
    int o=0;
    int p=0;
    int ans=0;
    int cnt=0;
    cin>>n>>m;
    int c=n*m;
    for(int i=1;i<=c;i++){
   	    cin>>a[i];
    }
    b=a[1];
    sort(a+1,a+c+1);
    for(int j=c+1;j>=0;j--){
        if(a[j]==b){
        	break;
		}
		else{
			cnt+=1;
		}
    }
	ans=cnt%n;
	if(ans>=0){
	    o=cnt/n+1;
	}
	if(o%2==0){
	    cout<<o<<" "<<n-ans+1;
	    return 0;
	}
	if(o%2==1){
		cout<<o<<" "<<ans;
		return 0;
	}
    return 0;
}

