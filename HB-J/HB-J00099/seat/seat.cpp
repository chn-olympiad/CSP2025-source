#include<bits/stdc++.h>
using namespace std;
int a[105],s[15][15],n,m;
int main(){
    freopen("seat.in","r",stdin);
    int XiaoR,c,r;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
        cin>>a[i];
    XiaoR=a[1];
    for(int i=1;i<=n*m;i++){
        for(int j=i;j<=n*m;j++){
            if(a[i]<a[j])
                swap(a[i],a[j]);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int k=1;
            while(k<=n*m){
                s[(k/n)+1][k%n]=a[k];
                k++;
            }
        }
    }
    for(int j=1;j<=m;j++){
        int qian=1,hou=m,i=0;
        while(i<=n){
            swap(s[i][qian],s[i][hou]);
            qian++;hou--;
            if(qian>n/2 && hou<n/2){
                i+=2;
                qian=1;hou=m;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(XiaoR==s[i][j]){
                c=i;r=j;
                break;
           }
        }
    }
     for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)
            cout<<s[i][j]<<" ";
        cout<<endl;

    }
    cout<<c<<" "<<r;
    freopen("seat.out","w",stdout);
    return 0;
}
