#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int a[1000001]={},n,k;
    int s64=0,s32=0,s16=0,s8=0,s4=0,s2=0,s1=0,s0=0;

    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }for(int i=0;i<=n;i++){
        if(a[i]==0){
            s0++;
        }else{
            if(a[i]>=64){
                s64++;
                a[i]-=64;
            }if(a[i]>=32){
                a[i]-=s32++;
            }if(a[i]>=16){
                a[i]-=s16++;
            }if(a[i]>=8){
                a[i]-=s8++;
            }if(a[i]>=4){
                a[i]-=s4++;
            }if(a[i]>=2){
                a[i]-=s2++;
            }if(a[i]>=1){
                a[i]-=s1++;
            }
        }
    }
    if(k==0){
        cout<<s1/2+s0/2;
    }
    else if(k==1){
        if(s1>s0){
            cout<<s0;
        }
        else cout<<s1;
    }
    else{
        cout<<1;
    }
    return 0;
}//#Shang4Shan3Ruo6Shui4
