#include<iostream>
#include<cstdio>
using namespace std;
string s;
int num[15];

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s;
    for(int i=0;i<s.size();i++)if('0'<=s[i] && s[i]<='9')num[s[i]-'0']++;
    int n[1000000]={},cnt=1;
    //for(int i=0;i<=9;i++)cout << num[i] << " ";
    for(int i=9;i>=0;i--){
        while(num[i]>0){
            n[0]++;
            n[cnt]=i;
            cnt++;
            num[i]--;
        }
    }
    for(int i=1;i<=n[0];i++)cout << n[i];
    return 0;
}
