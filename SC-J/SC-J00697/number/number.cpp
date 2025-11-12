#include<bits/stdc++.h>
using namespace std;
string s;
int a[10000],b=0;
bool cmp(int a,int b){
	if(a>b)return a;
	else return b;
}
int main(){
	freopen("number.in","w",stdin);
	freopen("number.out","r",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[b++]=(s[i]-'0');
		}
	}
	//sort(a,a+b,cmp);
	for(int i=0;i<b;i++){
		for(int j=i+1;j<b;j++){
			if(a[j]>a[i])swap(a[j],a[i]);
		}
	}
	for(int i=0;i<b;i++){
		cout<<a[i];
	}
	return 0;
} 