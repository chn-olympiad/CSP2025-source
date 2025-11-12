#include<bits/stdc++.h>
using namespace std;
int n(int i,int j){
	return i>j;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int a[s.size()],m=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[m]=int(s[i]-'0');
			m++;
		}
	}
	sort(a,a+m,n);
	for(int i=0;i<m;i++){
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
