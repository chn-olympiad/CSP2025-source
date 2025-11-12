#include<bits/stdc++.h>
using namespace std;
const int N=1e7+1;
string s;
int a[N];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int i=1;
    for(int q=0;q<s.size();q++){
        if(s[q]>='0'&&s[q]<='9'){
            a[s[q]-'0']++;
        }
    }
    for(int q=9;q>=0;q--){
        if(a[q]!=0){
            for(int w=1;w<=a[q];w++){
                cout<<q;
            }
        }
    }
    cout<<endl<<endl;
    return 0;
}
