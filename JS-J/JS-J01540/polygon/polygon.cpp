#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    int sticks[n+10];
    for(int i=1;i<=n;i++){
        cin>>sticks[i];
    }
    long long cnt=0;
    for(int i=1;i<=n;i++){
        int max=-1,tot=0;
        for(int j=i;j<=n;j++){
            if(sticks[j]>max) max=sticks[j];
            tot+=sticks[j];
            if(j-i>=2 && tot>2*max){
                cout<<i<<" "<<j<<endl;
                cnt++;
            }
        }
    }
    cout<<cnt<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}