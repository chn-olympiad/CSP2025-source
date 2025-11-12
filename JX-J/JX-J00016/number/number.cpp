#include<bits/stdc++.h>
using namespace std;
char a[10010];
int b[10010];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    int g=0;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0' && s[i]<='9'){
            a[i]=s[i];
            g++;
        }
        b[i]=a[i]-48;
    }
    for(int i=g;i>0;i--){
            if(b[i]>b[i-1]){
                swap(b[i],b[i-1]);
            }
        }
    for(int i=g;i>0;i--){
            if(b[i]>b[i-1]){
                swap(b[i],b[i-1]);
            }
        }
    for(int i=g;i>0;i--){
            if(b[i]>b[i-1]){
                swap(b[i],b[i-1]);
            }
        }
    for(int i=g;i>0;i--){
            if(b[i]>b[i-1]){
                swap(b[i],b[i-1]);
            }
        }
    for(int i=g;i>0;i--){
            if(b[i]>b[i-1]){
                swap(b[i],b[i-1]);
            }
        }
    for(int i=g;i>0;i--){
            if(b[i]>b[i-1]){
                swap(b[i],b[i-1]);
            }
        }
    for(int i=g;i>0;i--){
            if(b[i]>b[i-1]){
                swap(b[i],b[i-1]);
            }
        }
    for(int i=0;i<g;i++){
        cout<<b[i];
    }
    return 0;
}
