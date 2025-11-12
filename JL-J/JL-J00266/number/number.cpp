#include<bits/stdc++.h>
using namespace std;
int p[10];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s,s1,s2;
    cin>>s;
    for(int i=0;i<s.length();i++){
        if(s[i]<='9'&&s[i]>='0'){
            s1+=s[i];
        }
    }

    for(int i=0;i<s1.length();i++){
        if(s1[i]=='0') p[0]++;
        else if(s1[i]=='1') p[1]++;
        else if(s1[i]=='2') p[2]++;
        else if(s1[i]=='3') p[3]++;
        else if(s1[i]=='4') p[4]++;
        else if(s1[i]=='5') p[5]++;
        else if(s1[i]=='6') p[6]++;
        else if(s1[i]=='7') p[7]++;
        else if(s1[i]=='8') p[8]++;
        else if(s1[i]=='9') p[9]++;
    }
    for(int i=0;i<10;i++){
        for(int j=0;j<p[i];j++){
            cout<<i;
        }
    }

return 0;
}
