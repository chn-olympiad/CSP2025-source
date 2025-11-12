#include<bits/stdc++.h>
using namespace std;
char b[1000091];
int a[1000091],j=0;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    string s;
    cin>>s;
    for(int i=0;i<=s.size()-1;i++){
        if(s[i]=='0'){
            a[j]=0;
            j++;

        }
        if(s[i]=='1'){
            a[j]=1;
            j++;

        }
        if(s[i]=='2'){
            a[j]=2;
            j++;

        }
        if(s[i]=='3'){
            a[j]=3;
            j++;

        }
        if(s[i]=='4'){
            a[j]=4;
            j++;

        }
        if(s[i]=='5'){
            a[j]=5;
            j++;

        }
        if(s[i]=='6'){
            a[j]=6;
            j++;

        }
        if(s[i]=='7'){
            a[j]=7;
            j++;

        }
        if(s[i]=='8'){
            a[j]=8;
            j++;

        }
        if(s[i]=='9'){
            a[j]=9;
            j++;

        }

    }
    sort(a,a+j);
    for(int i=j-1;i>=0;i--){

        cout<<a[i];
    }

    return 0;
}

