#include<bits/stdc++.h>
using namespace std;
string s,s1;
int biggest=0,num=0;
int a[10000000]={0};
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    if(s.size()==1||s.size()==2&&s[0]>=s[1]){
        cout<<s;
        return 0;
    }
    for(int i=0;i<s.size();i++){
        if(isdigit(s[i])){
            num=max(num,int(s[i]));
            s1+=s[i];
        }
    }
    cout<<biggest<<endl;
    for(int i=0;i<s1.size();i++){
        for(int j=0;j<=num;j++){
            if(j==s1[i]){
                a[i]++;
                cout<<a[i];
            }
        }
    }
    for(int i=num;i>=0;i--){
        if(a[i]!=0){
            cout<<i;
        }

    }
    return 0;
}
