#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin>>a;
    int b,c[1000003];
    int d=0;
    for(int i=0;i<a.size();i++){
        if(a[i]=='0'){
            c[d]=0;
            d++;
        }
        if(a[i]=='1'){
            c[d]=1;
            d++;
        }
        if(a[i]=='2'){
            c[d]=2;
            d++;
        }
        if(a[i]=='3'){
            c[d]=3;
            d++;
        }
        if(a[i]=='4'){
            c[d]=4;
            d++;
        }
        if(a[i]=='5'){
            c[d]=5;
            d++;
        }
        if(a[i]=='6'){
            c[d]=6;
            d++;
        }
        if(a[i]=='7'){
            c[d]=7;
            d++;
        }
        if(a[i]=='8'){
            c[d]=8;
            d++;
        }
        if(a[i]=='9'){
            c[d]=9;
            d++;
        }
    }
    sort(c,c+d);
    for(int i=d-1;i>=0;i--){
        cout<<c[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
