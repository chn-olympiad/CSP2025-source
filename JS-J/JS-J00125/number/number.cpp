#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string s;
int op[N];
string asd="";
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int len=s.size();
    for(int i=0;i<len;i++){
        if(s[i]<='9'&&s[i]>='0')
        {
            int er=(int)(s[i]-'0');
            op[i]=er;
        }
        else{
            op[i]=-1;
        }
    }
    sort(op,op+len);
    for(int i=len-1;i>=0;i--){
        if(op[i]>=0){
            char u=(char)(op[i]+'0');
            asd=asd+u;
        }

    }
    cout<<asd;
    return 0;
}
