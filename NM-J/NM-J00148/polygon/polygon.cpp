#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,a[5005]={0},s[5]={0},x=0,h=0,g=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=3;;i++){
        x=0;
        h=0;
        int s[5]={0};
        for(int j=0;j<i;j++){
            s[j]=a[i*j];
            h+=s[j];
            x=max(x,s[j]);
            if(h==2*x){
                g++;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
