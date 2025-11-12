#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],k=0;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]=='0'){
            k++;
            a[k]=0;
        }
        if(s[i]=='1'){
            k++;
            a[k]=1;
        }
        if(s[i]=='2'){
            k++;
            a[k]=2;
        }
        if(s[i]=='3'){
            k++;
            a[k]=3;
        }
        if(s[i]=='4'){
            k++;
            a[k]=4;
        }
        if(s[i]=='5'){
            k++;
            a[k]=5;
        }
        if(s[i]=='6'){
            k++;
            a[k]=6;
        }
        if(s[i]=='7'){
            k++;
            a[k]=7;
        }
        if(s[i]=='8'){
            k++;
            a[k]=8;
        }
        if(s[i]=='9'){
            k++;
            a[k]=9;
        }
    }
    sort(a+1,a+k+1);
    for(int i=k;i>=1;i--)
        cout<<a[i];
    return 0;
}
