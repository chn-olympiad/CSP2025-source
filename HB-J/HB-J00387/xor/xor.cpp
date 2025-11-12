#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,a[100005];
    int num=0,o=0,l=0,m,p=n-1;

    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]==k){
            num++;
            a[i]=' ';
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=p;j++){
            for(int z=o;z<=l;z++){
                m=a[z]^m;
            }
            if(m==k){
                int m;
                num++;
            }
            o=o+1;
            l=l+n-p+2;
        }
        p--;
    }
    cout<<num+1;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
