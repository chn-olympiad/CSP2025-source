#include <bits/stdc++.h>

using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin>>a;
    int b=0;
    int c=0;
    int d=0;
    int e=0;
    int f=0;
    int g=0;
    int h=0;
    int i=0;
    int j=0;
    int k=10;
    for(int i=0;i<=a.size();i++){
        if(a[i]=='1'){
            b=1;
        }
        else if(a[i]=='2'){
            c=2;
        }
        else if(a[i]=='3'){
            d=3;
        }
        else if(a[i]=='4'){
            e=4;
        }
        else if(a[i]=='5'){
            f=5;
        }
        else if(a[i]=='6'){
            g=6;
        }
        else if(a[i]=='7'){
            h=7;
        }
        else if(a[i]=='8'){
            i=8;
        }
        else if(a[i]=='9'){
            j=9;
        }
        else if(a[i]=='0'){
            k=0;
        }
    }
    int arr[i];
    for(int i=0;i<=10;i++){
        if(j!=0){
            arr[i]=j;
            break;
        }
        else if(i!=0){
            arr[i]=i;
            break;
        }
        else if(h!=0){
            arr[i]=h;
            break;
        }
        else if(g!=0){
            arr[i]=g;
            break;
        }
        else if(f!=0){
            arr[i]=f;
            break;
        }
        else if(e!=0){
            arr[i]=e;
            break;
        }
        else if(d!=0){
            arr[i]=d;
            break;
        }
        else if(c!=0){
            arr[i]=c;
            break;
        }
        else if(b!=0){
            arr[i]=b;
            break;
        }
        else if(k!=10){
            arr[i]=k;
            break;
        }
    }
    for(int i=0;i<=10;i++){
        cout<<arr[i];
    }
    return 0;
}
