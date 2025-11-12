#include<bits/stdc++.h>
using namespace std;
string a;
int b[10000],ans;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,a);
	for(int i=0;i<a.size();i++)
		if(a[i]>='0'&&a[i]<='9'){
			b[ans++]=int(a[i]-'0');
		}
	sort(b,b+ans+1,cmp);
	for(int j=0;j<ans;j++){
		printf("%d",b[j]);
	}
	return 0;
}
