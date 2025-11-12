#include<bits/stdc++.h>
using namespace std;
int a,n[5005],b[5005],c;
int main(){
    freopen("polygon.in","w",stdin);
    freopen("polygon.out","r",stdout);
    cin>>a;
    for(int i=0;i<a;i++){
        cin>>n[i];
    }
    for(int i=0;i<a;i++){
        for(int j=0;j<a;j++){
            b[i]+=n[j];
            if(b[i]>=n[j]*2){
                c++;
            }
        }

    }
    cout<<c-a-1;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
