#include<bits/stdc++.h>
#define ll long long
using namespace std;
string a;
int num[20];
int main(){
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>a;
	int o=a.size();
	for(int i=0;i<o;i++){
		if(a[i]>='0'&&a[i]<='9'){
			int sum=int(a[i]-'0');
			num[sum]++;
		}
	}
	for(int i=9;i>=0;i--){
		if(num[i]==0)continue;
		for(int j=1;j<=num[i];j++){
			cout<<i;
		}
	}
	return 0;
}
