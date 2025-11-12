#include<bits/stdc++.h>
using namespace std;

string str="";
int num[10000]={0};
int cnt=0;
bool flag=0;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>str;
    for(int i=0 ; i<str.size() ; i++){
        if(str[i]>='0' && str[i]<='9'){
            num[cnt]=int(str[i]-48);
            cnt++;
        }
        if(str[i]!='0'){
            flag=1;
        }
    }
    sort(num,num+cnt);
    if(flag==0){
        cout<<0;
    }else{
        for(int i=cnt-1 ; i>=0 ; i--){
            cout<<num[i];
        }
    }
    return 0;
}
