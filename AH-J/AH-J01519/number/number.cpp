#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    int a[10];
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]=='0'){
            a[0]+=1;
            continue;
        }
        if(s[i]=='1'){
            a[1]+=1;
            continue;
        }
        if(s[i]=='2'){
            a[2]+=1;
            continue;
        }
        if(s[i]=='3'){
            a[3]+=1;
            continue;
        }
        if(s[i]=='4'){
            a[0]+=4;
            continue;
        }
        if(s[i]=='5'){
            a[5]+=1;
            continue;
        }
        if(s[i]=='6'){
            a[6]+=1;
            continue;
        }
        if(s[i]=='7'){
            a[7]+=1;
            continue;
        }
        if(s[i]=='8'){
            a[8]+=1;
            continue;
        }
        if(s[i]=='9'){
            a[9]+=1;
        }
    }
    for(int j=9;j>=0;j--){
        if(a[j]!=0){
            for(int i=0;i<a[j];i++){
                cout<<j;
            }
        }
    }
    return 0;
}
