#include <bits/stdc++.h>
using namespace std;

int n,m;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	cin>>n>>m;
	int r;
	int cnt=1;
	for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
        if(i==0&&j==0){
            cin>>r;
        }else{
            int x;
            cin>>x;
            if(x>r){
                cnt++;
            }
        }
        }
	}
    int p=(cnt%n==0)? n:cnt%n;
    int idx=(cnt%n==0)? cnt/n:cnt/n+1;
    if(idx%2==1){
        cout<<idx<<" "<<p;
    }else{
        cout<<idx<<" "<<n-p+1;
    }
    return 0;
}
