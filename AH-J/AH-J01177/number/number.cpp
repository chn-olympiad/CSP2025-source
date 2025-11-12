#include<bits/stdc++.h>
using namespace std;
//#Shang4Shan3Ruo6Shui4
int ap[1000100];
bool ooo(int x,int y){
    if(x>y) return 1;
    else return 0;
}
string a;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    char h,n=0;
    while(cin>>h){
        n++;
        a[n]=h;
    }
    int m=0;
    for(int i=1;i<=n;i++){
        if(a[i]=='0'){
            m++;
            ap[m]=0;
        }else if(a[i]=='1'){
            m++;
            ap[m]=1;
        }else if(a[i]=='2'){
            m++;
            ap[m]=2;
        }else if(a[i]=='3'){
            m++;
            ap[m]=3;
        }else if(a[i]=='4'){
            m++;
            ap[m]=4;
        }else if(a[i]=='5'){
            m++;
            ap[m]=5;
        }else if(a[i]=='6'){
            m++;
            ap[m]=6;
        }else if(a[i]=='7'){
            m++;
            ap[m]=7;
        }else if(a[i]=='8'){
            m++;
            ap[m]=8;
        }else if(a[i]=='9'){
            m++;
            ap[m]=9;
        }
    }
    sort(ap+1,ap+1+m,ooo);
    for(int i=1;i<=m;i++){
        cout<<ap[i];
    }
    cout<<endl;
    return 0;
}
