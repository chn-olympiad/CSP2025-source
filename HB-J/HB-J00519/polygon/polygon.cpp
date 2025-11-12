#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int l[n],t;
    for(int i=1;i<=n;i++){
        cin>>l[i];
    }
    sort(l+1,l+n+1);
    for(int i=3;i<=n;i++){

        for(int j=1;j<=n;j++){
            for(int k=j+1;k<=n;k++){
                for(int x=k+1;x<=n;x++){

                    if(l[j]+l[k]+l[x]>2*l[2]){
                        t++;
                        break;
                    }
                    else break;
                }
            }
        }

    }
    cout<<t/2%998224353;
    return 0;
}
