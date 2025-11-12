#include<bits/stdc++.h>
using namespace std;
string s;
int a[1005];

int f(char x){
    if(x=='0') return 0;
    if(x=='1') return 1;
    if(x=='2') return 2;
    if(x=='3') return 3;
    if(x=='4') return 4;
    if(x=='5') return 5;
    if(x=='6') return 6;
    if(x=='7') return 7;
    if(x=='8') return 8;
    if(x=='9') return 9;
    return 0;
}

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[f(s[i])]++;
        }
    }
    int z=0;
    for(int i=9;i>=0;i--){
        if(a[i]&&i!=0){
            z=1;
            for(int j=1;j<=a[i];j++) cout<<i;
        }
        else if(a[i]&&z==0&&i==0) cout<<0;
        else if(a[i]&&z==1&&i==0) for(int j=1;j<=a[i];j++) cout<<i;
    }
    return 0;
}
