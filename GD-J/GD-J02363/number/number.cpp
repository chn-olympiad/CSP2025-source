#include<bits/stdc++.h>
using namespace std;
int ans[1000010]; 
string str;
int main(){
	freopen("r","number.in",stdin);
	freopen("w","number.out",stdout);
	int p=0;
	cin>>str;
	int l=str.size();
	for(int i=0;i<l;i++){
		if(str[i]<='9'&&str[i]>='0'){
			ans[p]=str[i]-'0';
			p++;
		}
	}
	sort(ans,ans+p);
	if(ans[p-1]==0){
		cout<<0;
	}
	else{
		for(int i=p-1;i>=0;i--){
			cout<<ans[i];
		}
	}
	return 0;
}
