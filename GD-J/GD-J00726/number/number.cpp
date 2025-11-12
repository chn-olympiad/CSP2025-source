#include<bits/stdc++.h>
using namespace std;
string a;
int b[1000005],s;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[s]=a[i]-'0';
			s++;
		}
	}
	sort(b,b+s,cmp);
	for(int i=0;i<s;i++){
		cout<<b[i];
	}
	return 0;
} 
