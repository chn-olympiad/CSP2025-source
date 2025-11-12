#include <bits/stdc++.h>
using namespace std;
int a[200001];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,num=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(k==0){
            if(a[i]==0)
                num++;
            else if(i!=1)
                if(a[i]==1)
                    if(a[i-1]==1){
                        num++;
                        a[i]=2;
                    }
        }
        else if(k==1){
            if(a[i]==1)
                num++;
        }
    }
    cout<<num;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
