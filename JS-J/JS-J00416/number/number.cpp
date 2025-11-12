#include<bits/stdc++.h>
using namespace std;
string s;
int a[15];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>s;
    int number;
    memset(a,0,sizeof(a));
    for(int i=0;i<=s.length()-1;i++){
        if(s[i]>='0'&&s[i]<='9'){
            number=s[i]-'0';
            a[number]+=1;
            if(number==9) {
                cout<<'9';
                a[number]-=1;
            }
        }
    }
    for(int i=8;i>=0;i--){
        while(a[i]>0){
            cout<<i;
            a[i]-=1;
        }
    }
    return 0;
}