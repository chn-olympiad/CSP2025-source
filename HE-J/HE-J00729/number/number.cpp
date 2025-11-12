#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
string a;
cin>>a;
int c=a.size();
int b[c];
int length=0;
for(int i=0;i<c;i++){
         char d=a[i];
            if('0'<=d and d<='9'){
        b[length]=int(d)-48;
        length++;
    }
}
int ans=0;
for(int i=0;i<length;i++){
    int maxnum=0;
    for(int o=0;o<length;o++){
        maxnum=max(maxnum,b[o]);
    }
    ans=ans*10+maxnum;
    for(int o=0;o<c;o++){
        if(b[o]==maxnum){
            b[o]=0;
        }
    }

}
cout<<ans;
return 0;
}
