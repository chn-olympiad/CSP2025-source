#include <bits/stdc++.h>

using namespace std;

long long a[500005];

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    long long n,k,sum=0,l=0,s=0,m=-1;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        if(i<=m){
            continue;
        }
        if(a[i]==k){
            sum++;
            continue;
        }
        s = a[i];
        for(int j=i+1;j<n;j++){
            l=(s^a[j]);
            s = l;
            if(l==k){
                sum++;
                m = j;
                break;
            }
            if(l>k){
                break;
            }
        }
    }
    cout<<sum;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
