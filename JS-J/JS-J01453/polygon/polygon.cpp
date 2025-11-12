#include <bits/stdc++.h>
using namespace std;
#define int long long
int twoupn[]={1048576,524288,262144,131072,65536,32768,16384,8192,4096,2048,1024,512,256,128,64,32,16,8,4,2,1};
string ten2two(int x){
    string ans;
    for(int i=0;i<=20;i++){
        if(x-twoupn[i]>=0){
            x-=twoupn[i];
            ans+='1';
        }else{
            ans+='0';
        }
    }
    return ans;
}
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,indmaxqu,sumqu,cnt=0,a[5010];
    string qu;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=pow(2,n)-1;i++){
        sumqu=0;
        qu=ten2two(i);
        for(int j=0;j<n;j++){
            sumqu+=(qu[qu.size()-n+j]-'0')*a[j+1];
        }
        indmaxqu=qu.rfind('1');
        if(sumqu>a[indmaxqu+n-qu.size()+1]*2){
            cnt++;
        }
    }
    cout<<cnt;
}
