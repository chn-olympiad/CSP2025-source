#include<cstdio>
#include  <cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int a[100],b[10][10];
int merge_(int l,int r,int t){
    while(l<=r){
        int mid=l+(r-l)/2;
        if(a[mid]==t)return mid;
        else if(a[mid]<t)l=mid+1;
        else r=mid-1;
    }return -1;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int pnt;
    for(int i=0;i<n*m;i++){
        cin>>a[i];
        if(!i)pnt=a[i];
    }sort(a,a+n*m,greater<int>());
    for(int i=0;i<n*m;i++){
        int r=i/m,c=i%m;
        if(r%2)c=m-c-1;
        b[r][c]=a[i];
        if(a[i]==pnt){
            cout<<r+1<<' '<<c+1;
            break;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
