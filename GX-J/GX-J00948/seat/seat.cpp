#include<bits/stdc++.h>
using namespace std;
int a[101];
int main(){
    int n,m;
    cin>>n>>m;
    cin>>a[1];
    int r=n*m,l=a[1],h=1;
    for(int i=2;i<=r;i++){
        cin>>a[i];
        int j=i-1,x=a[i];
        while(a[j]<x&&j>=0){
            if(a[j]==l) h++;
            a[j+1]=a[j];
            j--;
        }
        a[j]==x;
    }
    //cout<<h;
    //3
    int x=0,y=1;
    bool g=true;
    int sum=0;
    for(int i=1;i<=h;i++){
        sum++;
        if(g) x++;
        else x--;
        if(sum==n){
            sum==0;
            y++;
            g=!g;
            if(g) x=1;
            else x=n;
        }
    }
    cout<<y<<" "<<x;
    return 0;
}
