#include<bits/stdc++.h>
using namespace std;
struct node{
	string n;
	int h;
}a[1000005];
string s;
bool cmp(node x,node y){
	if(x.n==y.n){
		return x.h<y.h;
	}
	return x.n>y.n;
}
int main(){
	//freopen("number","r",stdin);
	//freopen("number","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[i].n=s[i];
			a[i].h=i;
		}
	}
	sort(a,a+s.length(),cmp);
	for(int i=0;i<s.length();i++){
		cout<<a[i].n;
	}
	return 0;
}
