#include <bits/stdc++.h>
using namespace std;
#define ll long long
string s,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            if(s[i]=='0'){
                a0+=s[i];
            }
            else if(s[i]=='1'){
                a1+=s[i];
            }
             else if(s[i]=='2'){
                a2+=s[i];
            }
             else if(s[i]=='3'){
                a3+=s[i];
            }
             else if(s[i]=='4'){
                a4+=s[i];
            }
             else if(s[i]=='5'){
                a5+=s[i];
            }
             else if(s[i]=='6'){
                a6+=s[i];
            }
             else if(s[i]=='7'){
                a7+=s[i];
            }
             else if(s[i]=='8'){
                a8+=s[i];
            }
             else if(s[i]=='9'){
                a9+=s[i];
            }
        }
    }
    cout<<a9<<a8<<a7<<a6<<a5<<a4<<a3<<a2<<a1<<a0;
    return 0;
}
