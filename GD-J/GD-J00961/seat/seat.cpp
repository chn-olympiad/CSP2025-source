#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int x,y,n[101],first,s[11][11],sum=0;
    cin >> x >> y;
    for(int i=0;i<x*y;i++){
        cin >> n[i];
        if(i==0) first = n[i];
    }
    for(int i=0;i<x*y-1;i++){
        for(int j=0;j<x*y-1;j++){
            if(n[j]<=n[j+1]){
                swap(n[j],n[j+1]);
            }
        }
    }
    for(int i=1;i<=x;i++){
        if(i%2==1){
            for(int j=1;j<=y;j++){
                s[i][j]=n[sum];
                if(n[sum]==first){
                    cout << i << ' ' << j << endl;
                    return 0;
                }
                sum++;
            }
        }else{
            for(int j=y;j>=1;j--){
                s[i][j]=n[sum];
                if(n[sum]==first){
                    cout << i << ' ' << j << endl;
                    return 0;
                }
                sum++;
            }
        }    
    }
    return 0;
}
