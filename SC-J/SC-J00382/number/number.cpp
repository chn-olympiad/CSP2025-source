#include<bits/stdc++.h>
using namespace std;
int aa[15];
string a;
int n_s=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int len=a.size();
	for(int i=0;i<len;i++){
		char ch=a[i];
		if(ch>='0'&&ch<='9'){
			n_s++;
			aa[ch-48]++;
		}
	}
	//sort(aa+1,aa+n_s+1);
	for(int i=9;i>=0;i--){
		for(int j=1;j<=aa[i];j++){
			cout<<i;
		}
	}
	return 0;
} 