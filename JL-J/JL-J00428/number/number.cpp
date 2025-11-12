#include<bits/stdc++.h>
using namespace std;
string n;
long long a[10];
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);

cin>>n;
for(long long i=0;i<n.size();i++ ){
    if(n[i]>='0'&&n[i]<='9')
        a[n[i]-'0']++;
}
bool k=0;
for(long long i=9;i>0;i-- ){
   for(long long j=1;j<=a[i];j++ ){
            k=1;
    cout<<i;
}
}
if(k==0){
    cout<<"0";
}
else{
      for(long long j=1;j<=a[0];j++ ){
    cout<<"0";
}
}
return 0;

}
