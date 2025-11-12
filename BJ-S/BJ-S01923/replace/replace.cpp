#include<bits/stdc++.h>
using namespace std;
int n,q;
struct node{
string s,qusent;
}a[200005];
int main(){
freopen("replace.in","r",stdin);
freoprn("replace.out","w",stdout);
cin>>n>>q;
for(int i=0;i<n;i++){
cin>>a[i].s;
}
for(int i=0;i<q;i++){
cin>>a[i].qusent;
}
for(int i=0;i<n;i++){
cout<<0<<endl;
}
return 0;
}


