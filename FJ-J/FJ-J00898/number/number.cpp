#include <bits/stdc++.h>
using namespace std;
string s;
long long lens;
long long a[11]={0};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	lens=s.size();
	for(int i=0;i<lens;++i){
		if(s[i]>='0'&&s[i]<='9'){
			int k=int(s[i])-48;
			a[k]++;
		}
	}
	for(int i=9;i>=0;i--){
		if(a[i]!=0){
			for(int j=1;j<=a[i];j++){
				cout<<i;
			}
		}
	}
	return 0;
}
