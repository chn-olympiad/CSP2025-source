#include<iostream>
#include<cstdio>
using namespace std;
int m,n,c,sum=1;
string s,z;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    if(m==1){
        int pos=0x3f3f3f3f;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                pos=i+1;
                break;
            }
        }
        for(int l=1,a;l<=n;l++){
            cin>>a;
            if(a>=pos){
                c++;
                c%=998244353;
            }
        }
        for(int i=1;i<=n-1;i++){
            c*=i%998244353;
            c%=998244353;
        }
        cout<<c;
        return 0;
    }
    for(int l=1,a;l<=n;l++){
        cin>>a;
        if(a!=0){
            c++;
            c%=998244353;
            sum*=c%998244353;
            sum%=998244353;
        }
    }
    cout<<sum;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
