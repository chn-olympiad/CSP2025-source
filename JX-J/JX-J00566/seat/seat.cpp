#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a[105];
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int R=a[1];
    for(int i=1;i<=n*m;i++){
        for(int j=1;j<=n*m;j++){
            if(a[i]>a[j]){
                swap(a[i],a[j]);
            }
        }

    }
    for(int i=1;i<=n*m;i++){
        if(a[i]==R){
            //cout<<i<<endl;
            int pos=i%n;
            int cns=i/n;
            if(pos==0){
                if(cns%2==0)
                    cout<<cns<<" "<<1;
                else
                    cout<<cns<<" "<<n;
            }
            else{
                cns=cns+1;
                cout<<cns<<" ";
                if(cns%2==1){
                    cout<<pos;
                }
                else{
                    cout<<n-pos+1;
                }
            }

        }
    }

    return 0;
}

