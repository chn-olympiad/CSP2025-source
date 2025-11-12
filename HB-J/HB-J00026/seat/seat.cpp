#include<bits/stdc++.h>
using namespace std;
int a[105];
int main (){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,num,s,id;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    s=a[1];
    for(int i=1;i<=n*m;i++){
        for(int j=1;j<=n*m;j++){
            if(a[i]>a[j]){
                num=a[i];
                a[i]=a[j];
                a[j]=num;
            }
        }
    }
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==s){
            id=i;
        }
    }
    if(((id/n)+1)%2==1){
        if(id%n==0){
            cout<<(id-1)/n+1<<" "<<1;
        }
        else{
            cout<<(id-1)/n+1<<" "<<id%n;
        }
    }
    else{
        cout<<(id-1)/n+1<<" "<<1+m-(id%n);
    }


    return 0;
    fclose(stdin);
    fclose(stdout);
}
