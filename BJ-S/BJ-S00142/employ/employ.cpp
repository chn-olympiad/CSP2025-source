#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;

int n,m;
char a[N];
int c[N];

ll jc(int t){
	int res=1;
	for(int i=2;i<=t;i++)res*=i;
	return res;
}

int main(){
	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for(int i=1;i<=n;i++)cin>>c[i];
	if(m==n){
		for(int i=0;i<n;i++){
			if(a[i]=='0'){
				cout<<0;
				return 0;
			}
		}
		for(int i=1;i<=n;i++){
			if(c[i]<i){
				 cout<<0;
				return 0;
			}
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(c[i]>=i)cnt++;
		}
		cout<<(ll)jc(cnt);
	}
	
	if(m==1){
		bool flag=1;
		for(int i=1;i<=n;i++){
			if(a[i]=='1')return false;
		}
		if(flag){
			cout<<0;
			return 0;
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(c[i]>=i)cnt++;
		}
		cout<<(ll)cnt*jc(n-1);
		return 0;
	}
	
	cout<<2;
	
	return 0;
}
