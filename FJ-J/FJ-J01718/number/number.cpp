#include<iostream>
using namespace std;
string x;
int cnt[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>x;
	for (int i=0;i<x.size();i++){
		if (x[i]>='0' && x[i]<='9'){
			cnt[x[i]-'0']++;
		}
	}
	for (int i=9;i>=0;i--){
		while (cnt[i]){
			cout<<i;
			cnt[i]--;
		}
	}
	return 0;
}
//rp++;

