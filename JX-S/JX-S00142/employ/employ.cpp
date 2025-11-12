#include<bits/stdc++.h>
using namespace std;

int main(){
    //freopen("*.in", "r", stdin);
    //freopen("*.ans", "w", stdout);
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",n);
        int a[1e5+10][4]={};
        for(int i=1;i<=n;i++){
            int ls[5]={};
            for(int i=1;i<=3;i++){
                scanf("%d",&ls[i]);
            }
            sort(ls+1,ls+4,sx);
            a[1][1]=ls[1];
            a[1][2]=ls[2];
            a[1][3]=l3[3];
        }
    }	
    return 0;
}