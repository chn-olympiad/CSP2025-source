#include<bits/stdc++.h>
using namespace std;
char a[10000000],b[100000000],shuchu[10000000];
int l[100000001];
int jiance(char n){
    if(n-'0'>=1&&n-'0'<=10){
        return n-'0';
    }
    else return -1;
}


int main(){
  freopen("nubmer.in","r",stdin);
  freopen("number.out","w",stdout);
int n;
cin>>n;
for(int i=1;i<=n;i++){
   cin>>a[i]; 
}
for(int i=1;i<=n;i++){
    l[i]=jiance(a[i]);

}
for(int i=1;i<=n;i++){
    for(j=i;j>=2;j--){
        if(l[j]>l[j-1]){
            int t=l[j-1];
            l[j-1]=l[j];
            l[j]=t;
        }
    }
}
for(int i=1;i<=n;i++){
    if(l[i]>=0){
        cout<<l[i];
    }
}
return 0;
}