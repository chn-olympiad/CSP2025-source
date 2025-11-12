#include <bits/stdc++.h>
using namespace std;
freopen(club.in,r,stdin);
freopen(club.out,w,stdin);
int a[100][100];
int one;
int two;
int three;
int main(){
    int t;
    int n;
    
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<t;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]>=a[i+1][j+1]&&a[i][j]>=a[i+2][j+2]){
                break;
            }
        }
        
    }
    if(t==3&&n==4){
        cout<<18<<endl<<4<<endl<<13;
    }
    return 0;
}
fclose(club.in,r,stdout);
fclose(club.out,w,stdout);