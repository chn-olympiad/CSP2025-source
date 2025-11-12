#include<bits/stdc++.h>
using namespace std;
int b[100010];
int cnt;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	for(int i = 0;i < a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[cnt] = a[i]-'0';
			cnt++;
		}
	}

	sort(b,b+cnt);
	for(int i = cnt-1;i >= 0;i--){
		cout<<b[i];
	}
	return 0;
}
