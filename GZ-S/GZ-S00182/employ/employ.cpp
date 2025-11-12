//GZ-S00182 贵阳市云岩区中天中学 张颜淏 
#include<bits/stdc++.h>
using namespace std;
const int N=550;

int n,m,x;
unsigned long long ans=0;
vector <int> a;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);	
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>x;
		if(x!=0){
			a.push_back(x);
		}
	}
	int len=a.size();
	if(len<m){
		cout<<0;
		return 0;
	}
	ans=1;
	for(int i=len;i>=len-m-1;i--){
		ans*=i;
	}
	
	cout<<ans%998244353;
	return 0;
}
