#include<bits/stdc++.h>
using namespace std;
long long n,a[1000010],id;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<int(s.size());i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[id]=s[i]-'0';
			id++;
		}
	}
	sort(a,a+id);
	for(int i=id-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}
