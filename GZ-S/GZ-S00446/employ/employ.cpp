//GZ-S00486 贵阳市第十八中学 郭润山
#include<bits/stdc++.h>
using namespace std;
long long n,m,c[505];
unsigned long long cnt=1,pos;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=0;i<s.size();i++){
		if(s[i]=='0') pos++;
	}
	sort(c+1,c+n+1);
	if(s.find('0')==-1){
		
	}
	else if(m==1){
		for(int i=2;i<=n;i++){
			cnt*=i;
		}
		cout<<cnt%998244353<<endl;
	}
	else if(m==n){
		if(s.find('0')) cout<<0<<endl;
		else cout<<1<<endl;
	}
	else{
		for(int i=2;i<=n;i++){
			cnt*=i;
		}
		for(int i=pos;i>=2;i--){
			cnt/=i;
		}
		cout<<cnt<<endl;
	}
	return 0;
} 
