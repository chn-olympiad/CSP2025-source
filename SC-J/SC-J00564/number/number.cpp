#include<bits/stdc++.h>
using namespace std;
string a;
long long cnt[20];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(long long i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
			cnt[a[i]-'0']++;
		}
	}
	for(long long i=11;i>=0;i--){
		while(cnt[i]--){
			cout<<i;
		}
	}
	return 0;
} 