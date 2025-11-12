#include <bits/stdc++.h>
using namespace std;

long long n,k;
long long sr[500005];
bool f=true;

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >>n >>k;
    for(int i=1;i<=n;i++){
        cin >>sr[i];
        if(sr[i]!=1) f=false;
    }
    if(k==0 && f==true){
        cout <<n/2;exit(0);
    }
    if(n==1){
        if(sr[1]==k) cout <<1;
        else cout <<0;
        exit(0);
    }
    int cnt=0;
    if(f==false){
        if(k==0){
            for(int i=1;i<=n;i++){
                if(sr[i]==0) cnt++;
                else{
                    if(i!=n && sr[i]==sr[i+1]){
                        cnt++;i++;
                    }
                }
            }
            cout <<cnt;
        }else{
            for(int i=1;i<=n;i++){
                if(sr[i]==1) cnt++;
            }
            cout <<cnt;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
