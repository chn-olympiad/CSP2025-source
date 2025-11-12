#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);

    int n, jl[5003]={0}, temp[5003]={0};
    long long cnt=0;
    cin>>n;
    for(int i=0;i<=n;i++){
        cin>>jl[i];
        temp[i]=jl[i];
    }
    sort(temp, temp+5003);
    int s=3;
    while(s<=n){
        for(int i=0;i<n-s+1;i++){
            if(jl[i]+jl[i+1]+jl[i+2]>temp[5002]){
                cnt++;
            }
        }
        if(jl[n-(n-s)]+jl[n-(n-s-1)]+jl[0]>temp[5002]){
            cnt++;
        }
        if(jl[n-(n-s-1)]+jl[0]+jl[1]>temp[5002]){
            cnt++;
        }
        s++;
    }
    cout<<cnt%998244353;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
