#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    long long com=0,cnt=0,x,y,k,summ=1;
    int b[505];
    cin>>x>>y;
    cin>>k;
    for(int i=1;i<=x;i++){
        cin>>b[i];
        if(b[i]!=0&&b[i]>i-cnt){
            com++;
        }else{
            cnt++;
        }
    }
    cout<<com;
    return 0;
}
