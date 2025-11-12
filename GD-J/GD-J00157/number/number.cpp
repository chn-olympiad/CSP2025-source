#include<bits/stdc++.h>
using namespace std;
int num[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string a;
	cin>>a;
	bool ff=true;
	int ak=a.size();
	for(int i=0;i<ak;i++){
		if(a[i]>='0'&&a[i]<='9'){
			int sum=int(a[i]-'0');
			num[sum]++;
			if(sum!=0){
				ff=false;
			}
		}
	}
	if(ff){
		cout<<0;
		return 0;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=num[i];j++){
			cout<<i;
		}
	}
	return 0;
}//8:58 end ac?
