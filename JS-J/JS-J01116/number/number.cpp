#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int a[100001],d[100001],b=0,c=0,w=0;
    cin>>s;
    int q=0;
    while(s[q]){
        if(s[q]=='48'||s[q]=='a'||s[q]=='b'||s[q]=='c'||s[q]=='d'||s[q]=='e'||s[q]=='f'||s[q]=='g'||s[q]=='h'||s[q]=='i'||s[q]=='j'||s[q]=='k'||s[q]=='l'||s[q]=='m'||s[q]=='n'||s[q]=='o'||s[q]=='p'||s[q]=='q'||s[q]=='r'||s[q]=='s'||s[q]=='t'||s[q]=='u'||s[q]=='v'||s[q]=='w'||s[q]=='x'||s[q]=='y'||s[q]=='z'){}
        else{
            a[q]=s[q];
            b++;
        }
        w++;
        q++;
    }
    for(int j=1;j<w;j++){
        for(int i=1;i<w;i++){
            if(a[i]>a[i-1]){
                c=a[i-1];
                a[i-1]=a[i];
                a[i]=c;
            }
        }
    }
    for(int i=0;i<b;i++){
        a[i]-=48;
        cout<<a[i];
    }
    return 0;
}
