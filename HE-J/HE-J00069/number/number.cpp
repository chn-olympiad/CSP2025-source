#include<bits/stdc++.h>
using namespace std;
bool isint(char s){
    return (s-'0')>=0&&(s-'0')<=9;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
    string s;
    cin>>s;
    stack<int> tmp;
    int cnt=0;
    for(int i=0;i<s.size();i++){
        if(isint(s[i])) {tmp.push(s[i]-'0');cnt++;} 
    }
    int forp[cnt];
    for(int i=0;i<cnt;i++){
        forp[i]=tmp.top();
        tmp.pop();

    }
    sort(forp+0,forp+cnt);
    for(int i=cnt-1;i!=-1;i--){
        cout<<forp[i];
    }
}
