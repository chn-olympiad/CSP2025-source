#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
string a;
int b[N],tot;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> a;
	int len = a.size();
	for(int i=0;i<len;i++){
		if(a[i]>='0'&&a[i]<='9'){
			 b[++tot]=a[i]-'0';
		}
	}
	sort(b+1,b+1+tot,cmp);
	if(b[1]==0)cout<<0;
	else{
		for(int i=1;i<=tot;i++){
			cout << b[i];
		}
	}
	return 0;
}