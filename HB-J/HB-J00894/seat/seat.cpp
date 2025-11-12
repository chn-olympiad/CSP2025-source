#include<bits/stdc++.h>
using namespace std;
int c,r,a[1000006];
int main(){
    int s[1000008],n,m;
    cin>>n>>m;
    for(int i=0;i<=n*m-1;i++){
        cin>>s[i];
        while(s[i]>=s[i-1]){
            a[i]+=s[i];
        }
        if(n>a[i]){
            c+=1;
        }else{
            r+=a[i]%n
        }
    }
    cout<<c<<" "<<r<<endl;
    return 0;
}

