#include<bits/stdc++.h>
#include<string>
using namespace std;
int b[10000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int pos=0;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0' && a[i]<='9'){
			b[pos]=int(a[i]-'0');
			pos+=1;
		}
	}
	for(int i=0;i<pos-1;i++){
		for(int j=i+1;j<pos;j++){
			if(b[i]<b[j]){
				swap(b[i],b[j]);
			}
		}
	}
	for(int i=0;i<pos;i++){
		cout<<b[i];
	}
	return 0;
}
