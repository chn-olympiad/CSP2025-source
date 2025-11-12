#include<bits/stdc++.h>
using namespace std;
int n,a[1000100],ans=0;
void cnt(int i,int sum,int x,int mx){

    if(i>n){
            if(x>=3&&sum>2*mx){
                ans++;/*
                for(int i=1;i<=n;i++){
                    cout<<f[i];
                }
                cout<<endl;
                cout<<x<<" "<<sum<<" "<<mx<<endl;*/

            }

            return;
    }

    cnt(i+1,sum+a[i],x+1,max(a[i],mx));
    cnt(i+1,sum,x,mx);

}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    cnt(1,0,0,0);
    cout<<ans<<endl;
	return 0;
}/*

5
2 2 3 8 10
*/
