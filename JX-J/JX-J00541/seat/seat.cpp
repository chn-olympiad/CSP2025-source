#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int a[11][11];
    int b[101];
    int n,m;
    cin>>n>>m;
    int id;
    for(int i=1;i<=n*m;i++){
        cin>>b[i];
    }
    id=b[1];
    for(int i=n*m;i>=1;i--){
        bool flag=1;
        for(int j=n*m;j>=1;j--){
            if(b[j]>=b[j-1]){
                swap(b[i],b[i-1]);
                flag=0;
            }
        }
        if(flag){
            break;
        }
    }
    for(int s=1;s<=m*n;s++){
        int i,j;
        bool flag=1;
        i=1;
        j=1;
        a[i][j]=b[s];
        if(a[i][j]=id){
            cout<<i<<" "<<j<<endl;
            return 0;
        }
        if(flag==1){
           i++;
           if(i>n){
            i=n;
            j++;
            flag=0;
        }
        }
        else{
            i--;
            if(i<1){
                i=1;
                j++;
            }
        }

    }
    return 0;
}
