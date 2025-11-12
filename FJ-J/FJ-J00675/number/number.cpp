#include<bits/stdc++.h>
using namespace std;
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	int b[1000000]={};
	int cnt=0;
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[cnt]=a[i];
			cnt++;
		}
	}
	sort(b,b+cnt,cmp);
	for(int i=0;i<cnt;i++){
		cout<<char(b[i]);
	}
	return 0;
}
