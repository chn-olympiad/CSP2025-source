#include<bits/stdc++.h>
using namespace std;
int main(){
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;getline(cin,a);
	int b[a.size()+1]={0},j=0;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[j]=a[i]-'0';
			j++;
		}
	}
	sort(b,b+j,greater<int>());
	for(int i=0;i<j;i++) cout<<b[i];
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
