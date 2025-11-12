#include<bits/stdc++.h>
using namespace std;
void swap(int a,int b){
	int t=a;
	a=b;b=t;
	return;
}
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int a[100001];
	int n=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			a[n]=s[i]-'0';
			n++;
		}
	}
	sort(a,a+n,cmp);
	
	for(int i=0;i<n;i++){
		cout<<a[i];
	}
	return 0;

}

