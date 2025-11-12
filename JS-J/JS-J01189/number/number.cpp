#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string n;
	cin>>n;
	int ans[20]={};
	int o=n.size();
	for(int i=0;i<o;i++){
		if(n[i]>='0'&&n[i]<='9'){
			ans[n[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(ans[i]>0){
			cout<<i;
			ans[i]--;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
