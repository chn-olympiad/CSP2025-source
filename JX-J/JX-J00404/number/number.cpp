#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0;i<s.size;i++){
        cin>>s[i];
    }
    //s.sort(s.begin(),s.end);
    int flag;
    bool z=false;
    for(int i=0;i<s.size();i++){
        for(int j=0;j<s.size();i++){
            if(s[j]<s[j+1]){
                flag=s[j];
                s[j]=s[j+1];
                s[j+1]=flag;
                z=true;
            }
        }
        if(z=false){
            break;
        }
        z=false;
    }
    for(int i=0;i<s.size();i++){
        cout<<s[i];
    }
    return 0;
}
