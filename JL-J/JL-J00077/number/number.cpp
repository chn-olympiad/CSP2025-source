#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    long long n=0;
    int sum=0;
    string s;
    cin>>s;
    string a;
    for(int i=0;i<s.size();i++){
        int j=0;
        if(isalpha(s[i])){
            s[i]=a[j];
        }

    }
    int j=s.size();
    while(j){
        for(int i=1;i<s.size()-1;i++){
            int y=s[i-1];
            if(max(s[i],s[i-1])==s[i]){
                s[i-1]=s[i];
                s[i]=y;
            }
            int g=s[i];
            if(max(s[i],s[i+1])==s[i+1]){
                s[i]=s[i+1];
                s[i+1]=g;
            }
        }
        j--;
    }
    cout<<s;
    return 0;
}
