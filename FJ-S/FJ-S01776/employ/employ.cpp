#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","W",stdout);
	int n,m;
	cin>>n>>m;
	char a;
	int b;
	int cnt = 0;
	for(int i = 0;i < n;i++){
		cin>>a;
		if(a == '1'){
			cnt++;
		}
	}
	for(int i = 0;i < n;i++){
		cin>>b;
	}
	if(cnt<m){
		cout<<0;
	}else{
		cout<<cnt;
	}
	return 0;
}
