#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,cnt=1;
	cin>>n>>m;
	int a[n*m];
	for(int i=0;i<n*m;i++){
        cin>>a[i];
	}
    for(int i=1;i<n*m;i++){
        if(a[0]<a[i]) cnt++;
	}
	if(cnt%n==0){
        if(cnt/n%2==0) cout<<cnt/n<<" "<<1;
        else{
            cout<<cnt/n<<" "<<n;
        }
	}
	else{
        if(cnt<n){
            cout<<1<<" "<<cnt;
        }
        else{
            if(cnt/n%2==0) cout<<cnt/n+1<<" "<<cnt-cnt/n*n;
            else cout<<cnt/n+1<<" "<<cnt-cnt/n*n+n-1;
        }
	}
	return 0;
}
