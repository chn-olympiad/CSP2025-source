//GZ-S00359 贵阳雅礼高级中学（贵阳市第九中学）罗义凯
#include<bits/stdc++.h>
using namespace std;
string s;
int n,a[505];
long long su=0;
void di(int m,int q,int i){
	if(m==0){
		su++;
		return;
	}
	else if(i>n) return;
	else{
		if(q<=a[i]&&s[i]=='1'&&i<=n){
			di(m-1,0,i+1);
		}
		di(m,q+1,i+1);
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int m;
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	di(m,0,0);
	cout<<su%998244353;
	return 0;
} 
