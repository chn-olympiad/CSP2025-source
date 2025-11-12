#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    char a[1000005];
    cin>>s;
    for(int i=0,j=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[j]=s[i];
            j++;
        }
    }
    sort(a,a+strlen(a),cmp);
    for(int i=0;i<=strlen(a);i++){
        cout<<a[i];
    }
    return 0;
}
