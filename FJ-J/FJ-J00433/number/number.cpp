#include<bits/stdc++.h>
using namespace std;
long long num[12];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	for(long long i=0;i<a.size();i++){
		if(a[i]>='0' && a[i]<='9'){
			num[a[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(num[i]){
			cout<<i;
			num[i]--;
		}
	}
	return 0;
}

