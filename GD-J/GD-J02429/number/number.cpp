#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000010],tail;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int sz=s.size();
	for(int i=0;i<sz;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[tail]=s[i]-'0';
			tail++;
		}
	}sort(a,a+tail);
	for(int i=tail-1;i>=0;i--) cout<<a[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
