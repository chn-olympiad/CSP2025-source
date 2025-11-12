#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
string a;
cin>>a;
int n=1000010;
int b[n];
int c;
for(int i=0;i<a.length();i++){
    if(a[i]>='0'&&a[i]<='9'){
        b[i]=a[i]-'0';
        c++;
    }

}
for(int i=c-1;i>=0;i--){
    for(int l=0;l<i;l++){
        if(b[l]<b[l+1]){
            swap(b[l],b[l+1]);
        }
    }
}
for(int i=0;i<c;i++){
        if(b[i]!=0){
           cout<<b[i];
        }

}
return 0;
}
