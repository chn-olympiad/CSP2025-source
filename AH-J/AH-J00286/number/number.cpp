#include<iostream>
#include<cstdio>
using namespace std;

string s;
int t[20];

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if('0'<=s[i]&&s[i]<='9'){
            t[s[i]-'0']++;
        }
    }
    /*
    for(int i=0;i<=9;i++){
        cout<<t[i]<<" ";
    }
    */
    for(int i=9;i>=0;i--){
        int n=t[i];
        if(t[i]>0){
            for(int j=1;j<=n;j++){
                cout<<i;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
