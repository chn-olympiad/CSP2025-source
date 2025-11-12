#include<bits/stdc++.h>
using namespace std;
int main(){
    ifstream fin("xor.in");
    ofstream fout("xor.out");

    int n,k;
    fin>>n>>k;
    vector<int>num(n+1,0);
    vector<int>xornum(n+1,0);
    for(int i=1;i<=n;i++){
        fin>>num[i];
        xornum[i]=num[i]^xornum[i-1];
    }
    // for(int i=1;i<=n;i++){
    //     cout<<xornum[i]<<" ";
    // }
    // cout<<endl;
    int nbegin=0,nend=0,cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if((xornum[j]^xornum[i-1])==k){
                // cout<<xornum[j]<<" "<<xornum[i-1]<<" "<<(xornum[j]^xornum[i-1])<<" "<<k<<endl;
                if(j<=nend){
                    nend=j;
                    nbegin=i;
                    // cout<<i<<" "<<j<<endl;
                }else if(nbegin<i){
                    nend=j;nbegin=i;cnt++;
                    // cout<<i<<" "<<j<<endl;
                }
            }
        }
    }
    fout<<cnt;
    return 0;
}