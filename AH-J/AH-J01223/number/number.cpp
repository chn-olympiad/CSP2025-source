#include<bits/stdc++.h>
using namespace std;
string s;
char a[1000010];
int b;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.size();
	for(int i=0;i<=l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[b]=s[i];
			b++;
		}
	}
	sort(a,a+b);
	for(int i=b;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}
