#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;
int s;
int a[1000011],c=1,cnt=0,v=0,ans=0;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    while(s!=0){
        if(s%10>=0&&s%10<=9){
        v++;
        if(v==1)cnt++;
        else cnt*=10;
        a[v]=s%10;
        }
        if(s%10==0)c*=10;
        s/=10;
    }
    sort(a+1,a+v+1);
    for(int i=v;i>=1;i--){
        if(a[i]!=0){a[i]*=cnt;ans+=a[i];cnt/=10;v--;}
        else if(a[i]==0){ans*=10;cnt/=10;v--;}
    }
    cout<<ans/c;
    return 0;
}
