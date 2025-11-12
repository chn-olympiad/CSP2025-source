#include<bits/stdc++.h>
using namespace std;
int num[1000006],d;
string s;
bool cmp(int x,int y){
    return(x>y);
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            num[++d]=s[i]-'0';
        }
    }
    sort(num+1,num+d+1,cmp);
    for(int j=1;j<=d;j++){
        cout<<num[j];
    }
    return 0;
}
