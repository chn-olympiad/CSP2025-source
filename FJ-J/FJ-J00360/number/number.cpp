#include<bits/stdc++.h>
using namespace std;
string a;
long long b[15],n=1,q;
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
cin>>a;
for(int i=0;i<a.size();i++){
	if(a[i]>='0'&&a[i]<='9') b[a[i]-'0']++;
}
for(int i=9;i>=0;i--){
	if(i>=1&&b[i]!=0) q=1;
	if(i>=1){
	for(int j=1;j<=b[i];j++){
		cout<<i;
	}
	}else if(i==0&&q==0&&b[i]>=1) cout<<0;
	else if(i==0&&q==1&&b[i]>=1){
		for(int j=1;j<=b[i];j++){
		cout<<i;
		}
	}
}cout<<endl;
return 0;
}
