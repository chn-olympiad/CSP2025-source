#include<bits/stdc++.h>
using namespace std;
int t[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string n;
	cin>>n;
	for(int i=0;i<=n.size();i++){
		if(n[i]>='0' && n[i]<='9'){
			t[n[i]-'0']++;
		}
	}
	for(int i=9;i>=0;){
		if(t[i]==0){
			i--;
			continue;
		}
		cout<<i;
		t[i]--;
	}
	return 0;
} 
