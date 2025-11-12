#include<bits/stdc++.h>
#include<string>
using namespace std;
int sz[1000005], t[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	 
	string a;
	int i, n=0;
	cin>>a;
	for(i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
			t[a[i]-'0']++;;
		}
	}
	for(i=9;i>=0;--i){
		while(t[i]){
			cout<<i;
			t[i]--;
		}
	}
	return 0;
}
