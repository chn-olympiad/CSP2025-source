#include<bits/stdc++.h>
using namespace std;
int n,q;
string str[10010],str2[10010],strr;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for (int i=1;i<=n;i++){
		cin>>str[1]>>str[2];
	} 
	cin>>strr;
	for (int i=1;i<=n;i++){
		int cnt=0;
		if(strr.find(str[i])==strr.find(str2[i])){
			cnt++;
		}
		cout<<cnt;
	}
	
	return 0;
}

