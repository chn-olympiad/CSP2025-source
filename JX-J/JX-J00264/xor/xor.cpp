#include<bits/stdc++.h>
using namespace std;
int n,k,ls[500005];
int a0=0,a1=0;
bool a=1,b=1,c=1;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>ls[i];
        if(ls[i]==0)
            a0++;
        if(ls[i]==1)
            a1++;
        if(ls[i]!=1)
            a = 0;
        if(ls[i]>1)
            b = 0;
        if(ls[i]>255)
            c = 0;
    }
    if(a){
        cout<<n/2<<"\n";
    }
    else if(b){
        if(k==1)
            cout<<a1<<"\n";
        else{
            int ans = 0,z=0,xb=0x6f;
            for(int i=1;i<=n;i++){
                if(!ls[i])
                    ans++;
                else{
                    if(xb+1 == i && z){
                        ans++;
                        xb = 0;
                        z = 0;
                    }
                    else{
                        z = 1;
                        xb = i;
                    }
                }
            }
            cout<<ans<<"\n";
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
