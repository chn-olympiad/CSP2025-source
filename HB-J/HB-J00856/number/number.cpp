#include<bits/stdc++.h>
using namespace std;

freopen(number.in,"r",std);
freopen(number.out,"w",std);

int main(){
string c;
int n[11]={0},lon,i=0;
cin>>c;
lon=c.size();
while(i-lon){
int s=c[i]-'0';
if(s>=0&&s<=9){
n[s]++;
}
i++;
}
i=10;
while(i){
i--;
while(n[i]){
cout<<i;
n[i]--;
}
}
return 0;
}
