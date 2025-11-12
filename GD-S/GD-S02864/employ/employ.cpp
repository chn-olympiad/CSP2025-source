#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
long long human[100005];//可以承受几人淘汰而不离开的人数 
long long a,b,c,d,cs;
unsigned long long ans=1; 
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>a>>b;
	cin>>s;
	for(int i=0;i<=a;i++){
		d+=s[i]-'0';
	}
	if(d==a){
		for(int i=2;i<=a;i++){
			ans*=i;
		}
		cout<<ans;
		return 0;
	}//特判 
	for(int i=0;i<a;i++){
		cin>>c;
		human[c]++;
	}
	for(int i=10000;i>=0;i--){
		human[i]+=human[i+1];//预处理 
	}
	
	for(int i=1;i<=a;i++){
		if(!s[i]){
			cs++;//测试轮数+1
//			i++;
			continue;
		}
		if(human[cs]-i<=0){
			if(b<=0){
				cout<<ans;
				return 0;
			}
			cout<<0;
			return 0;
		}
		ans*=(human[cs]-i+1); 
		ans%=mod;
		b--;
		cout<<ans<<endl;
	}
	cout<<ans;
	return 0;
}
