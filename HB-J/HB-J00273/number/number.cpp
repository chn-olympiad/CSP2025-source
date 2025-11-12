#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.in","w",stdout);
    string s;
    cin>>s;
    int ans=s.size();
    for(int i=0;i<ans;i++){
        if(s[i]>='0'&&s[i]<='9'){
            if(ans==2){
                if(s[1]>s[0]){
                    cout<<s[1]<<s[0];
                }
                else{
                    cout<<s;
                }
                break;
            }
            else{
                cout<<s[i];
            }
        }
    }
    return 0;
}
