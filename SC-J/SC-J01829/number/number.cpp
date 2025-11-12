#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin>>s;
	int n=s.size();
	char a[n+5]={0};
	int k=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[k++]=s[i];
		}
	}
	sort(a,a+k,cmp);
	for(int i=0;i<k;i++){
		cout<<a[i];
	}
	return 0;
}