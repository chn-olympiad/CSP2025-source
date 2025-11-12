#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6+5;
int n,m;
int pos=0;
ll a[50][50];
ll s[200];
int cnt = 1;
int as;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>s[i];
	as=s[1];
	sort(s+1,s+n*m+1,greater<int>());
//	for(int i=1;i<=4;i++)cout<<s[i]<<" ";
//	cout<<endl;
	for(int j=1;j<=m;j++){
		if(pos==0){
			for(int i=1;i<=n;i++){
				a[i][j]=s[cnt];
				cnt++;
			}
			pos=1;
		}
		else if(pos==1){
			for(int i=n;i>=1;i--){
				a[i][j]=s[cnt];
				cnt++;
			}
			pos=0;
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			cout<<a[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(a[i][j]==as){
					cout<<j<<" "<<i<<endl;
					return 0;
				}
			}
		}
	return 0;
}

