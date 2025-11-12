#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	int n=0,cnt=0;
	cin>>a;
	int b[a.size()+9]={0};
	for(int i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[i]=a[i]-'0';
			if(a[i]=='0'){
				n++;
			}
		}
	}
	sort(b+0,b+a.size()-1,cmp);
	for(int i=0;i<a.length();i++){
		if(b[i]!=0){
			cout<<b[i];
			cnt=1;
		}
	}
	if(cnt==0){
		cout<<0;
		return 0;
	}
	for(int i=0;i<n;i++){
		cout<<0;
	}
	return 0;
}

