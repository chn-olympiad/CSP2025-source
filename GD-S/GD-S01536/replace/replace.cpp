#include<bits/stdc++.h>
using namespace std;
struct u{
string s1,s2;
};
u a[200000],x;
int main(){
freopen("replace.in","r",stdin);
freopen("replace.out","w",stdout);
int n,q;
cin>>n>>q;
for(int i=0;i<n;i++){
cin>>a[i].s1>>a[i].s2;
}
for(int i=0;i<q;i++){
int c=0;
cin>>x.s1>>x.s2;
if(x.s1.size()!=x.s2.size()){cout<<0<<endl;continue;}
for(int j=0;j<n;j++){

if(a[j].s1==x.s1||a[j].s2==x.s2)c++;

}
cout<<c;
}

return 0;
}
