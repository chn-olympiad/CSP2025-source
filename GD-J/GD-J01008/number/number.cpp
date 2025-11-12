#include<bits/stdc++.h>
using namespace std;
int main(){
	string n;
	long long t=1;
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	string ans[n.size()+10];
	int k=n.size();
	for(long long i=0;i<=k;i++){
		if(n[i]>='0'&&n[i]<='9'){
			ans[t]=n[i];
			t++;
		}
	}
	sort(ans+1,ans+t+1);
	for(long long i=t;i>=1;i--){
		cout<<ans[i];
	}
	return 0;
} 
