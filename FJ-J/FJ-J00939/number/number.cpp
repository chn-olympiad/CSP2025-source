#include<bits/stdc++.h>
using namespace std;
string s;
long long vis[100];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long l=s.size();
	for(long long i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			int x=s[i]-='0';
			vis[x]++;
		}
	}
	for(long long i=9;i>=0;i--){
		while(vis[i]!=0){
			cout<<i;
			vis[i]--;
		}
	}
	return 0;
}
