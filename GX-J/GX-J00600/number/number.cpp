#include<bits/stdc++.h>
using namespace std;
long long t[15];//0-9
string a;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	//jideigaizushu
	cin>>a;
	long long len=a.size();
	for(long long  i=0;i<len;i++){
		if(isdigit(a[i])){
			t[a[i]-'0']++;
		}
	}
	for(int i=10;i>=0;i--){
		if(t[i]==0){
			continue;
		}
		for(long long  j=1;j<=t[i];j++){
			cout<<i;
		}
	}
	return 0;
}
