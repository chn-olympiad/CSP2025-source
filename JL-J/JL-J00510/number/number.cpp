#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string s;
int a[N];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int j=0;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[j]=s[i]-'0';
            j++;
        }
    }
    sort(a,a+j,cmp);
    for(int i=0;i<j;i++){
        cout<<a[i];
    }
    cout<<endl;
    return 0;
}
