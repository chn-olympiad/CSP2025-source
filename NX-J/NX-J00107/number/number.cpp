#include<bits/stdc++.h>
using namespace std;
int s[1000005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	getline(cin,a);
	int k=0;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
			s[k]=a[i]-'0';
			k++;
		}
	}
	sort(s,s+k,cmp);
	for(int i=0;i<k;i++){
		cout<<s[i];
	}
	return 0;
}
