#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N];
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
string n;
cin>>n;
int len=n.size();
for(int i=0;i<len;i++){
 a[n[i]-'0']++;
}
for(int i=9;i>=0;i--){
	for(int j=0;j<a[i];j++)
	cout<<i;
	}
return 0;
}
