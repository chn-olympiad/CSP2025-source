#include<bits/stdc++.h>
#include<string>
freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);
using namespace std;
int main(){
    int n,k,sum=0,x=0;
    cin>>n>>k;
    int a[500010];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int dl=0,dr=0;
    for(int l=0;l<n;l++){
        for(int r=l;r<n;r++){
            for(int i=l;i<=r;i++){
                    x=x^a[i];
            }
            if(x==k && sum==0){
                sum++;
                dr=r;
            }
            else if(x==k){
                if(l<=dr)
                    continue;
                sum++;
                dr=r;
            }
            x=0;
        }
    }
    cout<<sum<<endl;
    return 0;
}
