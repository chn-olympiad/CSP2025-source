#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
string a;
char b,maxn;
int n1=0;
cin>>a;
char n[a.size()];
for(int i=0;i<a.size();i++){
    b=a[i];
    if(b<='9'){
        n[n1]=b;
        n1+=1;
        }
}
for(int i=0;i<n1;i++){
    maxn=i;
    for(int j=i;j<n1;j++){
        if(n[j]>n[maxn])
            maxn=j;
    }
    swap(n[maxn],n[i]);
}
cout<<n;
return 0; 
}
