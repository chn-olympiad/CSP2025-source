#include<bits/stdc++.h>
using namespace std;
string s;
int n[1000010];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int ch,w=0;
    ch = s.length();
    for(int i=0;i<ch;i++){
        if(s[i]=='0')n[i]=0;
        else if(s[i]=='1')n[i]=(int)s[i]-48;
        else if(s[i]=='2')n[i]=(int)s[i]-48;
        else if(s[i]=='3')n[i]=(int)s[i]-48;
        else if(s[i]=='4')n[i]=(int)s[i]-48;
        else if(s[i]=='5')n[i]=(int)s[i]-48;
        else if(s[i]=='6')n[i]=(int)s[i]-48;
        else if(s[i]=='7')n[i]=(int)s[i]-48;
        else if(s[i]=='8')n[i]=(int)s[i]-48;
        else if(s[i]=='9')n[i]=(int)s[i]-48;
        else n[i]=11;
    }
    for(int j=0;j<ch;j++){
        for(int l=0;l<ch;l++){
            if(n[l]<=n[l+1])swap(n[l],n[l+1]);
        }

    }
    for(int k=0;k<ch;k++){
        if(n[k]!=11)cout<<n[k];
    }
    return 0;
}
