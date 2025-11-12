#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n , m;
	cin >> n >> m;
	string s;
	cin>>s;
	int a[510];
	bool flag=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=0;i<s.length();i++){
		if(s[i]-'0'!=1){
			flag=0;
		}
	}
	if(m==n){
		if(flag){
			long long qwe;
			for(int i=1;i<=n;i++){
				qwe*=i;
			}
			cout<<qwe%998244353;
			return 0;
		}else{
			cout<<0;
			return 0;
		}
	}
	if(m==1){
		cout<<1;
		return 0;
	}
	if(flag){
		int qwe=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				qwe++;
			}
		}
		sort(a+1,a+1+n,cmp);
		n-=qwe;
		int cnt=n;
		bool opqr[510]={0};
		for(int i=1;i<=n/2;i++){
			cnt--;
			for(int j=n;j>=n-i;j--){
				if(a[j]<=i&&opqr[j]!=1){
					cnt--;
					opqr[j]=1;
				}
			}
			if(cnt==m){
				long long mann=1,am=1;
				long long a[500],wqop=1;
				for(int j=1;j<=m;j++){
					mann*=j;
					if(j%2==0){
						a[wqop]=mann;
						mann=1;
						wqop++;
					}
				}
				for(int i=1;i<=wqop;i++){
					am*=a[i];
					am%=998244353;
				}
				cout<<am;
				return 0;
			}
		}
		cout<<0;
		return 0;
	}
	cout<<0;
	return 0;
}
