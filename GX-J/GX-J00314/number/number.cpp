#include<bits/stdc++.h>
using namespace std;
long long s[1000003]={0};
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    char a;
    long long c=0;
    long long i=0;
    int p=5;
    while(cin>>a){
        if(a=='0'){
            c++;
            s[c]=0;
        }
        else if(a=='1'){
            c++;
            s[c]=1;
        }
        else if(a=='2'){
            c++;
            s[c]=2;
        }
        else if(a=='3'){
            c++;
            s[c]=3;
        }
        else if(a=='4'){
            c++;
            s[c]=4;
        }
        else if(a=='5'){
            c++;
            s[c]=5;
        }
        else if(a=='6'){
            c++;
            s[c]=6;
        }
        else if(a=='7'){
            c++;
            s[c]=7;
        }
        else if(a=='8'){
            c++;
            s[c]=8;
        }
        else if(a=='9'){
            c++;
            s[c]=9;
        }
    }
    sort(s,s+c+1);
    for(int j=c;j>0;j--){
        cout<<s[j];
    }
    return 0;}
