#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 100 ;
int a[N];
string s;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int f=0;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[++f]=s[i]-'0';
        }
    }
    sort(a+1,a+f+1);
    for(int i=f;i>=1;i--){
        cout<<a[i];
    }
    cout<<endl;
    return 0;
}
