#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int p=1,i=0,q=0,m=0;
    int a[1000]={-1};
    string s;
    cin>>s;
    while(s[i]!=' '){
        if(s[i]-'0'>-1&&s[i]-'0'<10){
            a[q]=s[i]-'0';
            q++;
        }
        i++;
    }
    for(int i=0;i<q;i++){
        for(int j=0;j<q;j++){
            if(a[i]>a[i+1]){
                m=a[i+1];
                a[i+1]=a[i];
                a[i]=m;
                m=0;
            }
        }
    }
    for(int i=0;i<=q;i++){
        cout<<a[i];
    }
    cout<<" ";
    return 0;
}
