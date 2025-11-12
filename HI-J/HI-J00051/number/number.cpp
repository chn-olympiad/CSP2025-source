#include<bits/stdc++.h>
using namespace std;
int b[1000005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int sum=0;
	string s;
	getline(cin,s);
//	for(int i=0;i<s.size();i++){
//		if(s[i]>='0'&&s[i]<='9'){
//			b[i]=s[i];
//			sum++;
//		}
//	}
//	sort(b,b+sum,cmp);
//	for(int i=0;i<sum;i++){ 
//		cout<<b[i];
//	}
cout<<s;
	return 0;
}
