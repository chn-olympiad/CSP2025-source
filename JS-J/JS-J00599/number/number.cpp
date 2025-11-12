#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int n=s.size()-1,a[10]={0};
    for(int i=0;i<=n;i++){
        if('0'<=s[i]&&s[i]<='9'){
            a[s[i]-'0']++;
        }
    }
    for(int i=9;i>=0;i--){
        for(int j=1;j<=a[i];j++){
            cout<<i;
        }
    }
    cout<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
