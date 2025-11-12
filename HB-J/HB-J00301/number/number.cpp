#include<bits/stdc++.h>
using namespace std;
string a;
int b[10001];
int k,l,p;
int main()
{


 cin>>a;
 for(int i=0;i<=a.size()-1;i++){
        if(a[i]>='0'&&a[i]<='9'){
            b[p]=a[i]-'0';
            p++;
        }
 }
 if(l==1){
    cout<<a;
    return 0;
 }
 for(int j=0;j<p;j++){
    for(int k=0;k<j;k++){
        if(b[j]>b[k]){
            swap(b[j],b[k]);
        }
    }
 }
 for(int m=0;m<p;m++){
    cout<<b[m];
 }

}
