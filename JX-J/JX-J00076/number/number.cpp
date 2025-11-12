#include<bits/stdc++.h>
using namespace std;
string s;
int a[100005],k;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<=s.size();i++){
		if(s[i]>=48&&s[i]<=57){
			a[++k]=((int)s[i])-48;
		}
	}
	for(int i=1;i<=k;i++){
		for(int j=i+1;j<=k;j++) {
		if(a[i]<a[j]) swap(a[i],a[j]);}
	}
	for(int i=1;i<=k;i++) cout<<a[i];
}
