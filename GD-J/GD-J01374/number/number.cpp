#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int o=0;
	string s;cin>>s;
	for(char v:s){
		if(v<='9'&&v>='0'){
			int f=v-'0';
			a[o++]=f;
		}
	}
	sort(a,a+o);
	for(int v=o-1;v>=0;v--){
		cout<<a[v];
	}
	return 0;
}
