#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	int c[100005];
	int cnt=0;
	getline(cin,a);
	for(int i=0;i<a.size();i++){
		cnt++;
		if(a[i]>='0' && a[i]<='9'){
			c[i]=a[i];
		}
	}
	sort(c,c+cnt,cmp);
	for(int i=0;i<cnt;i++){
		cout<<(char)c[i];
	}
	return 0;
}
