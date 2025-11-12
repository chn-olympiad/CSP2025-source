#include<bits/stdc++.h>
using namespace std;
int tong[20];
string r;
string ans;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>r;
	//cout<<r.size();
	//cout<<r[1];
	for(int i=0;i<r.size();i++){
		if(r[i]>='0'&&r[i]<='9'){
			tong[r[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		if(tong[i]!=0){
			for(int j=1;j<=tong[i];j++){
				char n=i+'0';
				ans+=n;
			}
		}
	}
	cout<<ans;
	return 0;
} 