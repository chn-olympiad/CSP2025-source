#include<iostream>
#include<string>
using namespace std;
string s;
int a[10];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int len=s.size();
    for(int i=0;i<len;i++){
        if(s[i]<'0'||s[i]>'9'){
            continue;
        }
        a[s[i]-'0']++;
    }
    for(int i=9;i>=0;i--){
        while(a[i]>0){
            cout<<i;
            a[i]--; 
        }
    }
    return 0;
}
