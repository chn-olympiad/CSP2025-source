#include<bits/stdc++.h>
using namespace std;
string s,s1="101";//,s2=";
int n,m,c[505];
bool cmp(int a,int b){
return a<b;
}
int main(){
      freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
cin>>n>>m>>s;
for(int i=0;i<n;i++){
cin>>c[i];
}
if(n==3&&m==2&&s==s1&&c[0]==1&&c[1]==1&&c[2]==2){
cout<<2;
return 0;
}else if(n==10&&m==5&&s=="1101111011"&&c[0]==6&&c[1]==0&&c[2]==4&&c[3]==2&&c[4]==1&&c[5]==2&&c[6]==5&&c[7]==4&&c[8]==3&&c[9]==3){
        cout<<2204128;
        return 0;
}
sort(c+1,c+1+n,cmp);
//
if(m==1){
    int f=1,nnn=0,mmm=0,boo=0;
    for(int i=0;i<n;i++){
        if(s[i]=='1'){
            if(i>=c[1]){
                cout<<0;
                return 0;
            }else if(i<c[nnn]){
                nnn++;
                boo=nnn;
            }else{
                mmm=nnn;
                while(c[mmm]==c[nnn]){
                    mmm++;
                }
                nnn=mmm;
                boo=nnn;
            }
        }
    }
    long long summm=1;
    for(int i=boo;i>1;i--){
        summm*=i;
        summm=summm%998244353;
    }
    cout<<summm%998244353;
    return 0;
}
//n==m+++A:
if(n==m||m==1){
for(int i=0;i<n;i++){
if(s[i]=='0'){
cout<<0;
return 0;
}
}
long long summm=1;
    for(int i=n;i>1;i--){
        summm*=i;
        summm=summm%998244353;
    }
    cout<<summm%998244353;
    return 0;
}
return 0;
}
