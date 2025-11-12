#include<bits/stdc++.h> 
using namespace std;
namespace A{
	string s;
	int a[1000010],b;
	bool cmp(int x,int y){
		return x>y;
	}
	int main(){
		freopen("number.in","r",stdin);
		freopen("number.out","w",stdout);
		cin>>s;
		for(int i=0;i<s.size();i++){
			if(s[i]<='9'&&s[i]>='0'){
				a[b++]=int(s[i]-'0');
			}
		}
		sort(a,a+b,cmp);
		for(int i=0;i<b;i++){
			cout<<a[i];
		}
		return 0;
	}
}
int main(){
	return A::main();
}