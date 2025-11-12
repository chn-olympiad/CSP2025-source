#include<bits/stdc++.h>
using namespace std;
int n,a[10005],m,s,sum=0;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            for(int k=j;k<=j+i-1;k++){
                s+=a[k];
                m=max(m,a[k]);
            }
            if(s>2*m&&i>=3){
                sum++;
            }
            s=0;m=0;
        }
    }
    cout<<sum;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
