#include<bits/stdc++.h>
using namespace std;

int n;
int a[5009];

int ru(int l,int ni,int p,int maxi){
    int t=0;
    if(ni==0){
        if(p>2*maxi){
            return 1;
        }
        else{
            return 0;
        }
    }
    for(int j=l;j<=n-ni+1;j++){
        if(l==n-nl+1){
            for(int i=1;i<=ni;i++){
                p+=a[n-i];
            }
        }
        t+=ru(j+1,ni-1,p+=a[j],max(maxi,a[j]));
    }
    return t;
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int title=0;
    for(int i=3;i<=n;i++){
        title+=ru(1,i,0,0);
    }
    cout<<title;
    return 0;
}
