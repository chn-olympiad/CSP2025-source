#include<bits/stdc++.h>
using namespace std;
string s;
int a[50];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>s;
    int n=s.size();
    //cout<<s;
    for(int i=0;i<n;i++){
        if(s[i]>='0'&&s[i]<=char(9+'0')){
            a[int(s[i]-'0')]++;
            //cout<<1<<" ";
        }
    }
    for(int i=9;i>=0;i--){
        for(int j=1;j<=a[i];j++){
            cout<<i;
        }
        //cout<<endl<<a[i]<<endl;
    }
    return 0;
}
