#include<bits/stdc++.h>
using namespace std;
int s[1000000];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    char a;


    int i=0,d=0,f;
    for(;(a=getchar())!='\n';){
        if(a>='0'&&a<='9'){
            s[i]=a-'1'+1;
            i++;
        }
    }
    for(int i1=i-1;i1>=0;i1--){
            f=0;
            int p;
            int io=0;
        for(;io<i;io++){
            if(s[io]==-1){
                continue;
            }
            else if(s[io]>f){
                f=s[io];
                p=io;
            }
        }
        cout<<f;
        s[p]=-1;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
