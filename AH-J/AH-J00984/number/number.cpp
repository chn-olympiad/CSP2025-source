#include<bits/stdc++.h>
using namespace std;
string s;
char a[1000010],c;
int n[20],l,f;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    l=s.size();
    for(int i=0;i<l;i++){
        if(s[i]>='0'&&s[i]<='9'){
            n[s[i]-48]++;
        }
    }
    for(int i=9;i>=0;i--){
        
        if(f==0&&i==0){
            cout<<0;
            return 0;
        } 
        if(i!=0&&n[i]>0)f++;
        for(int j=0;j<n[i];j++){
            cout<<i;
        }
    }
    return 0;
}
