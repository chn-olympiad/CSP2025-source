#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,n;
    string m[1001],o[1001];
    cin>>a>>n;
    for(int i=1;i<=a;i++){
        cin>>m[i]>>o[i];
    }
    for(int i=1;i<=n;i++){
        string s,l,il,jl;
        int p=0,cou=0;
        cin>>s>>l;
        for(int j=1;j<=s.length();j++){
            if(s[j]==l[j]){
                continue;
            }
            else{
                il+=s[j];
                jl+=l[j];
                for(int k=0;k<=a;k++){
                    if(m[k]==s[k] && o[k]==l[k]){
                        p==1;
                        cou++;
                        break;
                    }
                }
                if(p==0){
                    cout<<0<<endl;
                    break;
                }
            }
        }
        if(p==0){
            break;
        }
        cout<<cou<<endl;
    }
    return 0;
}
