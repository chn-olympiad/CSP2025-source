#include <bits/stdc++.h> 
using namespace std;
int a[505];
int jc(int x){
	if(x==1) return 1;
	return jc(x-1)*x;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int flag=true;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'){
			flag=0;
		}
	}
	if(flag==0&&m==n){
		cout<<0;
	} else if(flag==1&&m==n){
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				cout<<0;
				return 0;
			}
		}
	}else if(flag==1&&m!=n){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				cnt++;
			}
		}
		if(m+cnt>n){
			cout<<0;
		}else{
			cout<<jc(n);
		}
	}else if(m==1){
		cout<<jc(n);
	}
	return 0;
}
