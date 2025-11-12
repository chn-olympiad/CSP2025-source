#include<bits/stdc++.h>
using namespace std;
int n,k,nn,nnn,ans=0,c=1;
vector<long long>a[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        int l;
        cin>>l;
        a[1].push_back(l);
    }
    nn=n;
    nnn=n;
    while(nn>=1&&nnn>=1){
        int l;bool isf=1;
        nnn=0;
        if(a[c][0]==k){
            ans++;
            isf=0;l=0;
        }
        for(int i=0;i<nn-1;i++){
            if(a[c][i+1]==k){
                if(isf){
                    ans++;l=i+1;
                    isf=0;
                }
                else{
                    if(l+c-1<i+1){
                        ans++;l=i+1;
                    }
                }
            }
            if(a[c][i+1]==k||a[c][i]==k||a[c][i+1]==-1||a[c][i]==-1){
                a[c+1].push_back(-1);
            }
            else{
                a[c+1].push_back(a[c][i]^a[c][i+1]);
                nnn++;
            }
        }
        c++;
        nn--;
    }
    cout<<ans;
    return 0;
}
