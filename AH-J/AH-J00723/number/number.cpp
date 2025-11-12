#include <bits/stdc++.h>
using namespace std;
string s;
long long n[10]={0};
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(long long i=0;i<=s.size();i++){
        if(s[i]=='0')n[0]++;
        if(s[i]=='1')n[1]++;
        if(s[i]=='2')n[2]++;
        if(s[i]=='3')n[3]++;
        if(s[i]=='4')n[4]++;
        if(s[i]=='5')n[5]++;
        if(s[i]=='6')n[6]++;
        if(s[i]=='7')n[7]++;
        if(s[i]=='8')n[8]++;
        if(s[i]=='9')n[9]++;
    }
    for(long long i=9;i>=0;i--){
        for(long long j=n[i];j>=1;j--)cout<<i;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
