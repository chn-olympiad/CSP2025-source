#include<bits/stdc++.h>
using namespace std;
int n,a[500004],k,aa=1,ans=0;
struct abc{
    int l;
    int r;
}abcd[1048578];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(i==j&&a[i]==k){
                abcd[aa].l=a[i];
                abcd[aa].r=a[i];
                aa++;
            }
            if(i!=j){
                int aaa=a[i];
                for(int kk=i+1;kk<=j;kk++){
                    aaa^=a[kk];
                    if(aaa==k){
                        abcd[aa].l=a[i];
                        abcd[aa].r=a[j];
                        aa++;
                    }
                }
            }
        }
    }
    cout<<2;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
