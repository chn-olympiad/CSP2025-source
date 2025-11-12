#include <bits/stdc++.h>

using namespace std;
string b;
int c=0;
char a[1000001];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>b;
    for(int i=0;i<b.size();i++){
        if(b[i]>='0'&&b[i]<='9'){
            a[c]=b[i];
            c++;
        }
    }
    sort(a,a+c);
    for(int i=c+1;i>=0;i--){
        cout <<a[i];
    }


    return 0;
}
