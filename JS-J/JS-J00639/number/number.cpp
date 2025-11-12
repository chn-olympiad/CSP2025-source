#include<bits/stdc++.h>
using namespace std;
string s;
int n=0,a[10000005];

int main(){
freopen("number","r",stdin);
freopen ("number","w",stdout);
cin>>s;
int b=1;
for(int i=0;i<=s.size();i++){

int h=s[i]-'0';
if(h<=9&&h>=0){
        n++;
        a[b]=h;
        b++;

}
}

for(int i=1;i<=n;i++){
   for(int j=i+1;j<=n;j++){
    if(a[i]<a[j]){
        swap(a[i],a[j]);
    }
   }
}
for(int i=1;i<=n;i++){
     cout<<a[i];
}




return 0;

}

/*nt h=s[i]-'0';
if(h<=9&&h>=0){
        n++;*/
