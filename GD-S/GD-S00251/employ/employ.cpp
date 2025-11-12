#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
	}
	int res=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='1'){
			res++;
		}
	}
	if(res<m){
		cout<<0;
	}
	else{
		score(time(NULL));
		
	}
	return 0;
} 
