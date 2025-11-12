#include <bits/stdc++.h>
using namespace std;
int a[1000005]; 
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int t=s.size(); 
	int y=0;
	for(int i=0;i<t;i++){
		if(s[i]>='0'&&s[i]<='9'){
			int q=s[i]-48;
			a[y]=q;
			y=y+1;
		}
		else{
			continue;
		}
	} 
	sort(a,a+y);
	for(int i=y-1;i>=0;i--){
		cout<<a[i];
	} 
	return 0;
}
