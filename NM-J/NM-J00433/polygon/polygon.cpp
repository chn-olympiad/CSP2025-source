#include <bits/stdc++.h>
using namespace std;

int n;
int sr[5005];

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >>n;
    for(int i=1;i<=n;i++){
        cin >>sr[i];
    }
    if(n==3){
        int sum=sr[1]+sr[2]+sr[3];
        int Max=max(max(sr[1],sr[2]),sr[3]);
        if(sum>2*Max) cout <<1;
        else cout <<0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
