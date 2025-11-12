#include <bits/stdc++.h>
using std::cout;
using std::cin;
using std::vector;

int qjsize,k,ans=0;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>qjsize>>k;
    int a[qjsize]={-1};
    for(int i=0;i<qjsize;i++){
        cin>>a[i];
        if(a[i]==k){
            ans++;
            a[i]=-1;
        };
    }
    bool complete=false;
    while(!complete){
        complete=true;
        for(int i=0;i<qjsize;i++){
            if(a[i]!=-1){
                complete=false;
                int yhh=a[i];
                int last_i = i;
                i++;
                while(a[i]!=-1&&i<qjsize){
                    yhh^=a[i];
                    i++;
                }
                if(yhh==k){
                    ans++;
                    for(int j=last_i;j<=i;j++){
                        a[j]=-1;
                    }
                }else{
                    a[last_i]=-1;
                }
                i=last_i;
            }
        }
    }
    cout<<ans;
    cout<<"\n";
    return 0;
}
