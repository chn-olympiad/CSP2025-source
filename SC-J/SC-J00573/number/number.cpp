#include<bits/stdc++.h>
using namespace std;
int b[1001];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;int c=0;
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0' && a[i]<='9'){
			b[c++]=a[i]-'0';
		}
	}
	for(int i=0;i<c;i++){
		for(int j=i+1;j<c;j++){
			if(b[i]<b[j])swap(b[i],b[j]);
		}
	}
	if(b[0]==0){
		cout<<0;
		return 0;
	}
	for(int i=0;i<c;i++){
		cout<<b[i];
	}
	return 0;
}