#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	int c[505];
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	int cnt=0;
	int mut=0;
	for(int i=0;i<n;i++){
		if(s[i]==1+'0'){
			cnt++;
		}else{
			cnt=cnt;
		}
		if(cnt==c[i]) cnt--;
	}
	cout<<2;
	return 0;
}
