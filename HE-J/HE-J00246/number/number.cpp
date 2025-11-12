#include<bits/stdc++.h>
using namespace std;
int a[1000006]; 
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin>>s;
	int n=s.size();
	int cnt=0;
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){	
			cnt++;
			a[cnt]=int(s[i]-'0');
		}
	}
	sort(a+1,a+1+cnt,cmp);
	if(a[1]==0){
		cout<<0<<'\n';
	}else{
		for(int i=1;i<=cnt;i++){
			cout<<a[i];
		}
	} 
	
	return 0;
}
