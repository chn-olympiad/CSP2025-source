#include<bits/stdc++.h>
using namespace std;
char a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	long long h=1;
	if(s.size()==1) cout<<s;
	else for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[h]=s[i];
            h++;
		} 
	}
	sort(a+1,a+h+1);
	for(int i=h;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}