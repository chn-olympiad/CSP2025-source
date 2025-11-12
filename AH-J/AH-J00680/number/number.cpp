#include<bits/stdc++.h>
using namespace std;
string s;
int t[10];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int len=s.size();
    for(int i=0;i<len;i++){
        if(s[i]>='0'&&s[i]<='9'){
           t[s[i]-'0']++;
        }
    }int Y=0;
    for(int i=9;i>=0;i--){
        if(t[i]){
           if(i!=0){
                Y=1;
                while(t[i]--){
                   cout<<i;
                }
            }else{
                if(Y==0){
                    cout<<0;
                }else{
                    while(t[i]--){
                        cout<<i;
                    }
                }
            }
        }
    }
    return 0;
}
