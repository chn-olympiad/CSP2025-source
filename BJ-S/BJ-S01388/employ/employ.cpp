#include<bits/stdc++.h>
using namespace std;
const int N=510;
int c[N];
int n,m;
string hard;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    scanf("%d%d",&n,&m);
    cin>>hard;
    if(n==1&&n>=m){
        printf("1\n");
    }else{
          printf("0\n");
    }

    return 0;
}
