#include<bits/stdc++.h>
using namespace std;
string s;
int a[114514],k=0;
int cpp(int x,int y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            k++;
            a[i]=s[i]-'0';
        }
    }
    sort(a,a+1002,cpp);
    for(int i=0;i<k;i++){
        cout<<a[i];
    }
    return 0;
}
