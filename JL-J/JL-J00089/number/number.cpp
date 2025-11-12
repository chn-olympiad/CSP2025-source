#include<bits/stdc++.h>
using namespace std;
int a[1090000];
int sum=0;
string s;
int cmp(int x,int y){
    return x>y;
};
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[i]=s[i]-'0';
            sum++;
        }
    }
    sort(a,a+1009000,cmp);
    for(int i=0;i<sum;i++){
        cout<<a[i];
    }
    return 0;
}
