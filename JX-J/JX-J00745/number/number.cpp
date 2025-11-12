#include<bits/stdc++.h>
using namespace std;
int N=1000000;
bool qw(int a,int b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    int a[N+1]={0},j=0,r=1,m=-100000;
    cin>>s;
    for(int i=0;i<=s.size();i++){
        if(s[i]=='0'){
            j++;
            a[j]=0;
        }
        else if(s[i]=='1'){
            j++;
            a[j]=1;
        }
        else if(s[i]=='1'){
            j++;
            a[j]=1;
        }
        else if(s[i]=='2'){
            j++;
            a[j]=2;
        }
        else if(s[i]=='3'){
            j++;
            a[j]=3;
        }
        else if(s[i]=='4'){
            j++;
            a[j]=4;
        }else if(s[i]=='5'){
            j++;
            a[j]=5;
        }
        else if(s[i]=='6'){
            j++;
            a[j]=6;
        }
        else if(s[i]=='7'){
            j++;
            a[j]=7;
        }
        else if(s[i]=='8'){
            j++;
            a[j]=8;
        }
        else if(s[i]=='9'){
            j++;
            a[j]=9;
        }
    }
    sort(a+1,a+j+1,qw);
    for(int i=1;i<=j;i++){
        cout<<a[i];
    }
    return 0;
}
