#include<bits/stdc++.h>
using namespace std;
int n,m;
int a,b;
int cnt=0;
int main(){
        freopen("seat.in","r",stdin);
        freopen("seat.out","w",stdout);
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(i==1&&j==1) cin>>a;
                else cin>>b;
                if(b>a)cnt++;
            }
        }
        cnt++;
        int h=cnt/n;
        if(cnt%n!=0){
            h++;
            int k=cnt%n;
            if(h%2==0){
                cout<<h<<" "<<(n-k+1);
            }else{
                cout<<h<<" "<<k;
            }
        }else{
            cout<<h<<" ";
            if(h%2==0)cout<<1;
            else cout<<n;
        }
        fclose(stdin);
        fclose(stdout);
    return 0;
}
