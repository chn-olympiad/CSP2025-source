#include<bits/stdc++.h>
using namespace std;
int cmp(int x,int y){
	return x>y;
}
int a[100001];
int d;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int b=s.size();
	for(int i=0;i<b;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[i]=s[i]-'0';
			d++;
		}
	}
	sort(a,a+b,cmp);
	for(int i=0;i<d;i++){
		cout<<a[i];
	}
	return 0;
}