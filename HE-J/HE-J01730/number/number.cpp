#include<bits/stdc++.h>
using namespace std;
string a;
int tong[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i = 0;i<=9;i++){
		tong[i] = 0;
	}
	int l = a.size();
	l--;
	for(int i = 0;i<=l;i++){
		if(a[i]>='0' && a[i]<='9'){
			tong[a[i]-'0']++;
		}
	}
	for(int i = 9;i>=0;i--){
		while(tong[i]!=0){
			cout<<i;
			tong[i]--;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
