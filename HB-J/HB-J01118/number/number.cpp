#include <iostream>
using namespace std;
string s;
int book[15];
bool y;
int  main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int l=s.size();
    for(int i=0;i<l;i++){
        if(s[i]>='0'&&s[i]<='9'){
                book[s[i]-'0']++;
                if(s[i]!='0') y=1;
        }
    }
    if(!y){
        cout<<0;
        return 0;
    }
    for(int i=9;i>=0;i--){
        for(int j=1;j<=book[i];j++){
            cout<<i;
        }
    }
}
