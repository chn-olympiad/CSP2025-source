#include<iostream>
#include<algorithm>
using namespace std;

bool cmp(char x,char y){
    return x > y;
}

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string str;
    cin>>str;
    string res="";
    for(int i=0;i<str.size();++i){
        if(str[i]>='0'&&str[i]<='9'){
            res+=str[i];
        }
    }
    sort(res.begin(),res.end(),cmp);
    cout<<res<<endl;
    return 0;
}