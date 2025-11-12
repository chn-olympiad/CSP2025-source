#include <bits/stdc++.h>
using namespace std;

string chen(string s1,string s2){
    int b[100000];
    int c=100000;
    if(s1.size()<s2.size()){
        string c=s1;
        s1=s2;
        s2=c;
    }
    for(int i=s2.size();i>=1;i--){
        for(int j=s1.size();j>=1;j--){
            int jw=0;
            b[c] = (i*j+jw)/10;
            c--;
            jw=(i*j)%10;
        }
    }
    if(jw!=0) b[c]=jw;
    string d;
    for(int i=100000;i>=c;i--){
        d += to_string(b[i])
    }
    return d;
}
string chu(string s1,string s2){
    if(s1.size()<s2.size()) return s1;

}

int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m,c[505];
    string s;
    cin >> n >> m;
    cin >> s;
    for(int i=1;i<=n;i++){
        cin >> c[i];
    }
    flag=true;
    for(int i=0;i<=s.size();i++){
        if s[i]='0';
        flag=false;
        break;
    }
    string dp[1000];
    dp[1]="1";
    //if(flag){
        //for(int i=2;i<=n;i++){
            //dp[i]=chen(dp[i-1],to_string(i))
        //}
        //cout << dp[n];
    //}
    if(flag){
        long long sum=1;
        for(int i=2;i<=n;i++){
            sum *=i
        }
        cout << sum%998224353;
    }
    else{
        cout << 0;
    }
    return 0;
}
