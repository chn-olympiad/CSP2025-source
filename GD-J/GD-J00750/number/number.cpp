#include<bits/stdc++.h>
using namespace std;
long long b[100000],j;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[j]=a[i]-'0';
			j++;
		}
		else{
			continue;
		}
	}
	sort(b,b+j,cmp);
	for(int i=0;i<j;i++){
		cout<<b[i];
	}
	return 0;
}
