#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int n,num=0;
    cin>>n;
    int a[100005]={0},b[100005]={0};
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a,a+n+1);
    for(int i=3;i<=n;i++){
        for(int j=1;j<=n-i;j++){
            int u=0,s=i+1;
            while(s--){
                u+=a[j+s-1];
            }
            cout<<u<<endl;
            if(u>a[j+i-1]*2){
                num++;
            }
        }
    }
    cout<<num;
    return 0;
}

