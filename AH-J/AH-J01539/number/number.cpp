#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int a[10]={0},c;
    string b;
    cin>>b;
    for(int i=0;i<b.size();i++){
        if(b[i]<='9'&&b[i]>='0'){
            c=b[i]-'0';
            a[c]++;
        }
    }
    if(a[1]!=0||a[2]!=0||a[3]!=0||a[4]!=0||a[5]!=0||a[6]!=0||a[7]!=0||a[8]!=0||a[9]!=0){
        for(int i=9;i>=0;i--){
            while(a[i]>0){
                cout<<i;
                a[i]--;
            }
        }
    }
    else cout<<0;
    return 0;
}
