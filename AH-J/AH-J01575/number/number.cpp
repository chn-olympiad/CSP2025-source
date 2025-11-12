#include<bits/stdc++.h>
using namespace std;
int cmp(int x,int y){
    if(x>y){
        return true;
    }return false;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int a[1000001]={},maxn=0;
    string s;
    cin>>s;
    for(int i=0;i<s.length();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[maxn]=s[i]-'0';
            maxn++;
        }
    }
    sort(a,a+maxn,cmp);
    for(int i=0;i<maxn;i++){
        cout<<a[i];
    }
    return 0;
}//#Shang4Shan3Ruo6Shui4
