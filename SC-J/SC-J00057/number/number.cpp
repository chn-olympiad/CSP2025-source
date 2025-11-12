#include<bits/stdc++.h>
using namespace std;
string s;
int a[20];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if('0'<=s[i]&&s[i]<='9'){
			int cnt=s[i]-'0';
			a[cnt]++;
		}
	}
	for(int i=9;i>=0;i--){
		if(a[i]==0)continue;
		while(a[i]--)cout<<i;
	}
	cout<<endl;
	return 0;
}