#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
string s;
int b[300],cnt;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int n=s.size();
    s=" "+s;
    for(int i=1;i<=n;i++){
        b[s[i]]++;
        if(s[i]>='0'&&s[i]<='9'){
            cnt++;
        }
    }
    if(b['0']==cnt){
        cout<<0;
        return 0;
    }
    for(int i='9';i>='0';i--){
        for(int j=1;j<=b[i];j++){
            cout<<i-'0';
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
