#include<bits/stdc++.h>
using namespace std;
int a[1005];
string s;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<=s.size()-1;i++){
        a[s[i]]++;
    }
    for(int i='9';i>='0';i--){
        while(a[i]!=0){
            cout<<i-'0';
            a[i]--;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

//#Shang4Shan3Ruo6Shui4
