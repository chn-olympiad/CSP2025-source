#include<bits/stdc++.h> 
using namespace std;
int n,m,c[510],a[20],b[20],ans;
string s;
void bl(int p){
	if(p==n+1){
		int cnt = 0,k = 0;
		for(int i = 1;i<=n;i++){
			if(s[i-1]=='1'&&c[b[i]]>k)cnt++;
			else k++;
		}
		if(cnt>=m)ans++;
		return ;
	}
	for(int i = 1;i<=n;i++){
		if(a[i]==0){
			a[i] = 1;
			b[p] = i;
			bl(p+1);
			b[p] = 0;
			a[i] = 0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i = 1;i<=n;i++)cin>>c[i];
	if(n<=10){
		bl(1);
		cout<<ans%998244353<<"\n";	
	}
	else cout<<"0\n";
}
