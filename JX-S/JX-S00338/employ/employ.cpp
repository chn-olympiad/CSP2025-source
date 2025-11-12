#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","r",stdout);
    int n,m,sq=0,ly=0,sum=1;
    cin>>n>>m;
    int s[n+5],c[n+5];
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    for(int i=0;i<n;i++){
        cin>>c[i];
    }
    while(ly!=m){
        for(int i=0;i<n;i++){
            if(c[i]<sq){
                if(s[i]==1){
                    ly++;
                }
                else{
                    sq++;
                }
            }
            else{
                sq++;
            }
            if(ly==m){
                sum++;
            }
        }
    }
    sum=sum%998224353;
    cout<<sum<<endl;
    return 0;
}
