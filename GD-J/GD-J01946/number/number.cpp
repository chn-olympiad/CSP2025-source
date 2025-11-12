#include<bits/stdc++.h>
using namespace std;
string s;
int ans,sum[10000005];
int c(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size(),cnt=0;
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			sum[++cnt]=s[i]-'0';
		}
	}
	sort(sum+1,sum+1+cnt,c);
	for(int i=1;i<=cnt;i++){
		cout<<sum[i];
	}
	return 0;
}
