#include<bits/stdc++.h>
using namespace std;
int num[1000005];
bool vis[1000005];
int top=0;
void add(int addnum){
    num[top]=addnum-48;
    top++;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    string s;
    cin>>s;
    int n=s.length();
    for(int i=0;i<n;i++){
        if(s[i]<='9' && s[i]>='0') {add(s[i]);}
    }
    //kaishishuchu
    for(int loc=9;loc>=0;loc--){
        for(int i=0;i<=top-1;i++){
            if(num[i]==loc){
                cout<<loc;
            }
        }
    }
    cout<<endl;
    return 0;
}
