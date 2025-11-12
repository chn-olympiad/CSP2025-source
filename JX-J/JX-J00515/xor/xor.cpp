#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int n,m,num=0;
    int a[500005]={0};
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m!=0){
        int b=0,c=0;
        for(int i=1;i<=n;i++){
            b++;
            c+=a[i];
            if(c==m or c/2==m){
                b=0;
                c=0;
                num++;
            }
            if(c>m){
                i=i-b+1;
                b=0;
                c=0;
            }
        }
    }else{
        for(int i=1;i<=n;i++){
            if(a[i]==0){
                num++;
            }
        }
    }
    cout<<num;
    return 0;
}
