#include <bits/stdc++.h>
using namespace std;
string a;
int c[1000005],d;
bool cmp(char a,char b){
    return a>b;
}
int main(){
    freopen("number4.in","r",stdin);
    freopen("number4.out","w",stdout);
    cin>>a;
    for(int i=0;i<a.length();i++){
        if('0'<=a[i] && a[i]<='9'){
            c[d]=a[i]-'0';
            d++;
        }
    }
    sort(c,c+d,cmp);
    for(int i=0;i<d;i++)
        cout<<c[i];
    fclose(stdin);
    fclose(stdout);
    return 0;
}





