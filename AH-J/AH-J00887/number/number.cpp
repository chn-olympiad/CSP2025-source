#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
bool cmp(int a,int b){
return a>b;
}
int n[2000005],c=0;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin>>a;    
   return 0;
    int len=a.size();
    for(int i=0;i<len;i++){
        if(a[i]>='0'&&a[i]<='9'){
         n[c]=a[i]-'0';c++;
        };
    };
    sort(n,n+c,cmp);
    for(int i=0;i<c;i++){
        cout<<n[i];
    }
    return 0;
   
}
