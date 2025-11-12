#include<iostream>
#include<string>
#include<algorithm>
using namespace std;


const int maxn=1e6+10;
string s;
int cnt,a[maxn+100];

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    cin>>s;

    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[cnt]=s[i]-'0';
            cnt++;
        }
    }

    sort(a,a+cnt);

    while(cnt--){
        cout<<a[cnt];
    }

    return 0;
}
