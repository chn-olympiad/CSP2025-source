#include<bits/stdc++.h>
using namespace std;
ifstream fin("xor.in");
ofstream fout("xor.out");
int a[1145014];
int n,k;
int main(){
    fin>>n>>k;
    bool flag=true;
    bool fla=true;
    for(int i=0;i<n;i++){
        fin>>a[i];
        if(a[i]!=1){
            flag=false;
        }
        if(a[i]>1){
            fla=false;
        }
    }
    if(flag==true and k==0){
        fout<<n/2;
    }
    else if(k==0 and fla){
        int ans=0;
        for(int i=0;i<n;i++){
            if(a[i]==0){
                ans++;
            }
            else{
                if(a[i+1]==1){
                    ans++;
                    i++;
                }
            }
        }
        fout<<ans;
    }
    else if(k==1 and fla){
        int ans=0;
        for(int i=0;i<n;i++){
            if(a[i]==1){
                ans++;
            }
            else{
                if(a[i+1]==1){
                    ans++;
                    i++;
                }
            }
        }
        fout<<ans;
    }
    else{
        int ans=0;
        int l=0;
        int z=0;
        bool q=false;
        for(int i=0;i<n;i++){
            z=a[i];
            for(int j=i-1;j>=l;j--){
                if(z==k){
                    q=true;
                }
                z=z xor a[j];
            }
            if(z==k){
                q=true;
            }
            if(q){
                l=i+1;
                ans++;
                q=false;
            }
        }
        fout<<ans;
    }
}
