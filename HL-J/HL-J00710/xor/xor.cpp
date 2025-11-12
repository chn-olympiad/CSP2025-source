#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    vector<int> S(n);
    for(int i = 0;i<n;i++){
        cin>>S[i];
    }
    int i = S[0],ans= 0;
    while(i<n){
        int temp = S[i];
        if(temp == k){
            ans++;
            i++;p++;
        }
        int p = i+1;
        while(temp!=k&&p<S.size()){
            temp^=S[p];
            p++;
        }
        if(temp==k){
            i=p;
            p = i+1;
            ans++;
        }else{
            i++;
            p++;
        }
    }
    cout<<ans<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
