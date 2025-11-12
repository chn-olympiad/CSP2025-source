#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;

struct R{
    int a,b,c;
}a[N]={0};

bool sx(int x,int y){
    return x>y;
}

int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            int ls[5];
            for(int j=0;j<n;j++){
                cin>>ls[j];
            }
            sort(ls+1,ls+4,sx);
            a[i].a=ls[1];
            a[i].b=ls[2];
            a[i].c=ls[3];
        }


        int alen=0,blen=0,clen=0;

    }

    return 0;
}
