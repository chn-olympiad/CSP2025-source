#include<bits/stdc++.h>
using namespace std;
int m,n,b[105];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>b[i];
    }
    int t=b[1];
    for(int i=1;i<=n*m;i++){
        for(int j=1;j<=n*m-i;j++){
            if(b[j]<b[j+1]){
                swap(b[j],b[j+1]);
            }
        }
    }
    int c=1;
    int flag=1;
    for(int i=1;i<=m;i++){
        if(flag==1){
            for(int j=1;j<=n;j++){
                if (b[c]==t){
                    cout<<i<<" "<<j;
                }
            c++;
            }
        }
        else{
            for(int j=n;j>=1;j--){
                if (b[c]==t){
                    cout<<i<<" "<<j;
                }
            c++;
            }
        }
        flag=flag*-1;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
