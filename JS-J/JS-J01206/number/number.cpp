#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[10];
int main(){
    //Open IO Files
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if('0'<=s[i]&&'9'>=s[i])a[s[i]-'0']++;
    }
    for(int i=9;i>=0;i--){
        for(int j=0;j<a[i];j++)printf("%d",i);
    }
    printf("\n");
    //Close IO Files
    fclose(stdin);
    fclose(stdout);
    return 0;
}