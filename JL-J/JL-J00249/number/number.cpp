#include<bits/stdc++.h>
using namespace std;
int b[1000001],k=0,s=9,m=0;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin>>a;
    for(int i=0;i<=a.size();i++){
        if(a[i]=='0'){
            m++;
        }
        else if(a[i]=='1'){
            b[i]=1;
            k++;
        }
        else if(a[i]=='2'){
            b[i]=2;
            k++;
        }
        else if(a[i]=='3'){
            b[i]=3;
            k++;
        }
        else if(a[i]=='4'){
            b[i]=4;
            k++;
        }
        else if(a[i]=='5'){
            b[i]=5;
            k++;
        }
        else if(a[i]=='6'){
            b[i]=6;
            k++;
        }
        else if(a[i]=='7'){
            b[i]=7;
            k++;
        }
        else if(a[i]=='8'){
            b[i]=8;
            k++;
        }
        else if(a[i]=='9'){
            b[i]=9;
            k++;
        }
    }
    for(int i=1;i<=9;i++){
        for(int j=0;j<=a.size();j++){
            if(b[j]==s){
                cout<<s;
            }
        }
        s--;
    }
    for(int i=1;i<=m;i++){
        cout<<0;
    }
    return 0;
}
