#include<bits/stdc++.h>
using namespace std;
int a[1000];
int n,m;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
    cin>>n>>m;
    int t,sum=0;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        if(i==1){
            t=a[i];
            continue;
        }
        if(a[i]>t){
            sum++;
        }
    }
    int l=sum/n+1;
    if(l%2==1){
        int h=sum%n;
        cout<<l<<" "<<h+1;
    }
    else{
        int k=sum%n;
        cout<<l<<" "<<n-k;
    }
	return 0;
}
