#include<bits/stdc++.h>
#define int long long
using namespace std;
int num[10];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int len=a.size();
	for(int i=0;i<len;i++){
		if(a[i]<='9'&&a[i]>='0'){
			num[(int)(a[i]-'0')]++;
		}
	}
	if(num[9]==0&&num[8]==0&&num[7]==0&&num[6]==0&&num[5]==0&&num[4]==0&&num[3]==0&&num[2]==0&&num[1]==0){
		cout<<0;
		return 0;
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<num[i];j++){
			cout<<i;
		}
	}
	return 0;
} 