#include<bits/stdc++.h>
using namespace std;
int main(){;
    int n,m;
    int a[n*m+1];
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>a[i];
    }
    int count=0;
    int s=a[0];
    for(int i=0;i<n*m;i++){
       if(a[i]>s)count++;
    }
    int arr[11][11];
    int x=0,y=0;
    for(int k=0;k<count;k+=n+1){
    for(int i=0;i<count;i++){
        x++;
        if(x==n-1)break;
    }
    for(int i=n;i<count;i++){
        if(y<m)y++;
        break;
    }
    for(int i=n+1;i<count;i++){
        if(x>0)x--;
        break;
    }
    for(int i=2n+1;i<count;i++){
        if(y<m)y++;
        break;
    }
    }
    cout<<x<<" "<<y<<endl;
    return 0;
}
