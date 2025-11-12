#include<bits/stdc++.h>
using namespace std;
int n,m,arr[501]={},fl=1,sumc0=0,sum=1;
string str;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>str;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        if(arr[i]==0)sumc0++;
    }for(int i=0;i<str.length();i++){
        if(str[i]==0){
            fl=0;
        }
    }if(fl){
            if(sumc0==0){
                for(int i=2;i<=n;i++){
                    sum*=i;
                }cout<<sum;
            }else{
                if(n==m)cout<<0;
            }
        }

    }fclose(stdin);
    fclose(stdout);
    return 0;
}
