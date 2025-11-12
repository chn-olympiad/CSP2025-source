#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    vector<char> num;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0' && s[i]<='9'){
            num.push_back(s[i]);
        }
    }
    char max;
    int p;
    for(int i=0;i<num.size();i++){
        for(int j=0;j<num.size();j++){
            if(max<num[j]){
                max=num[j];
                p=j;
            }
        }
        if(max>0){
            cout<<max;
        }
        max=-1;
        num[p]=0;
    }
    return 0;
}