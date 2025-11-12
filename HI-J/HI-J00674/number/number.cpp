#include<bits/stdc++.h>
using namespace std;
bool cmp(int a1,int a2){
	return a1>a2;
}
int a[1001];
int main(){
	string s;
	cin>>s;
	for(int i=0,j=1;i<s.size();i++,j++){
		if(s[i]%s[i]==1){
			a[j]=s[i];
		}
	}
	cout<<a;
	sort(a,a+1,cmp);
	cout<<a;
	

	
	return 0;
}
