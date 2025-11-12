#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	string b="";
	for(long unsigned int i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
			b+=a[i];
		}
	}
	sort(b.begin(),b.end()); 
	if(b[b.size()-1]=='0'){
		puts("0");return 0;
	}
	for(long unsigned int i=b.size()-1,j=0;i>j;i--,j++){
		swap(b[i],b[j]);
	}
	cout<<b;
	return 0;
}
