#include<bits/stdc++.h>
using namespace std;
int n,m,y=1,h[100010];
long long s=1;
string st; 
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	cin>>st;
	for(int i=0;i<st.size();i++){
		if(st[i]=='0'){
			y=0;
			break;
		}
	}
	if(m==1||y){
		for(int i=1;i<=n;i++){
			cin>>h[i];

		}
		for(int i=1;i<=n;i++){
			s*=i;
			s%= 998244353;
		}
		cout<<s;
	}
	return 0;
} 
