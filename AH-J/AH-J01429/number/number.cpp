#include<bits/stdc++.h>
using namespace std;
string s;
bool cmp(char x,char y){
	return x>=y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]<'0'||s[i]>'9'){
            s.erase(i,1);
            i--;
        }
    }
    for(int i=0;i<s.size();i++){
        bool f=0;
        for(int j=i;j<s.size();j++){
            if(s[j]<s[j+1]){
                swap(s[j],s[j+1]);
                f=1;
            }
        }
        if(!f){
            break;
        }
    }
    while(s[0]=='0'&&s.size()>1){
        s.erase(0,1);
    }
    cout<<s;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
