#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    long long n,k;
    cin>>n >> k;
    vector<long long> a(n+1);
    for(long long i = 1;i<=n;i++){
        cin>>a[i];
    }
    long long c = 0;
    long long num = 0,b = 1;

    while(c<=n-1){
        bool f = true;
        long long sum = a[b];
        for(long long i = b+1;i<=b+c;i++){
            if(a[i]==-1){
                sum=-1;
                break;
            }
            sum = sum^a[i];
        }
        if(sum == k){
            num++;
            for(long long i = b;i<=b+c;i++){
                a[i]=-1;
            }
        }


        for(long long i = b+1;i<=n;i++){
            if(a[i]!=-1){
                b = i;
                f = false;
                break;
            }
        }

        if(b>n-c || f){
            for(long long i = 1;i<=n;i++){
                if(a[i]!=-1){
                    b = i;
                    break;
                }
            }
            c++;
        }
    }

    cout<<num;
    return 0;
}

