#include<bits/stdc++.h>
using namespace std;

string a;
long long n;
char b[10000000];
int main(){
    n=1;
    cin>>a;
    for(int i=0;i<a.size();i++){
        if(a[i]=='1'||a[i]=='2'||a[i]=='3'||a[i]=='4'||a[i]=='5'||a[i]=='6'||a[i]=='7'||a[i]=='8'||a[i]=='9'||a[i]=='0'){
            b[n]=a[i];
            n++;
        }
    }
    sort(b+1,b+1+n);
    for(int i=n;i>=1;i--){
        cout<<b[i];
    }

    return 0;
}

