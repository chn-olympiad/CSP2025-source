#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    int a[1000001]={},t=1,ans=0;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]=='0'){
            a[t]=0;
            t++;
        }
        else if(s[i]=='1'){
            a[t]=1;
            t++;
        }
        else if(s[i]=='2'){
            a[t]=2;
            t++;
        }
        else if(s[i]=='3'){
            a[t]=3;
            t++;
        }
        else if(s[i]=='4'){
            a[t]=4;
            t++;
        }
        else if(s[i]=='5'){
            a[t]=5;
            t++;
        }
        else if(s[i]=='6'){
            a[t]=6;
            t++;
        }
        else if(s[i]=='7'){
            a[t]=7;
            t++;
        }
        else if(s[i]=='8'){
            a[t]=8;
            t++;
        }
        else if(s[i]=='9'){
            a[t]=9;
            t++;
        }
    }
    t--;
    for(int i=1;i<=t+1;i++){
        for(int j=1;j<t;j++){
            if(a[j]<a[j+1]){
                swap(a[j],a[j+1]);
            }
        }
    }
    for(int i=1;i<=t;i++){
        //cout<<a[i]<<endl;
        cout<<a[i];
        //cout<<a[i+1]<<endl;
    }
    return 0;
}
