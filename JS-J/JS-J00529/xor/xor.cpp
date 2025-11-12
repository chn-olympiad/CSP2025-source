#include <iostream>
#include <cstdio>
#include <string>
#include <map>
using namespace std;
int n,k,l[500005],tot[500005];map<int,bool>m;
string dectobin_non_reverse(int num){
    int i=1;string s="";
    while(num)s+=char((num&1)+'0'),i<<=1,num>>=1;
    while(s.size()<20)s+='0';
    return s;
}
int bintodec_non_reverse(string str){
    int x=1;int ans=0;
    for(int i=0;i<str.size();i++){
        if(str[i]=='1')ans+=x;
        x<<=1;
    }
    return ans;
}
int back_xor(int x_in_int,int y_in_int){
    string x=dectobin_non_reverse(x_in_int),y=dectobin_non_reverse(y_in_int),ans="";
    int i=0;
    while(x[i]=='1'||y[i]=='1'){ans+=(x[i]?(!y[i]):y[i]);cout<<x[i]<<" "<<y[i]<<"\n";i++;}//deeeeeeeeeeeebug
    return bintodec_non_reverse(ans);
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    scanf("%d",&l[1]);tot[1]=l[1];bool flag=1;
    for(int i=2;i<=n;i++){
        scanf("%d",&l[i]);
        if(l[i]!=0&&l[i]!=1)flag=0;
        tot[i]=tot[i-1]^l[i];
    }
    if(k==0){printf("%d",n>>1);return 0;}
    if(flag){
        int sum0=0,sum1=0;
        for(int i=1;i<=n;i++){
            if(l[i])sum1++;
            else sum0++;
        }
        if(sum1&1){cout<<sum1;return 0;}
    }
    int sum=0;
    for(int i=1;i<=n;i++){
        if(l[i]==k){m.clear();sum++;continue;}
        auto it=m.find(back_xor(k,tot[i]));
        for(auto i:m)cout<<"fs"<<i.first<<" "<<i.second<<"    ";//debug sentence delete after using
        if(it==m.end()){m[tot[i]]=1;cout<<1<<"\n";continue;}//part debug delete a part after using
        sum++;m.clear();
    }
    printf("%d",sum);
    return 0;
}
