#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    int a[1000000];
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int num=0;
    int x,y;
    bool z=false;
    for(int i=1;i<=n;i++){
        if(a[i]==k){
            num++;
            z=true;
        }else{
            x=a[i];
            if(z){
                y=a[i];
            }else{
                y=y|x;
                if(y==k){
                    num++;
                    z=true;
                    y=0;
                }
            }
        }
    }
    cout<<num<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
