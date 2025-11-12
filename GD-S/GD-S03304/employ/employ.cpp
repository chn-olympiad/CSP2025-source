#include<bits/stdc++.h>
using namespace std;
#define long long ll
const int N=505;
int dfs(){
	
}
int c[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	srand(time(0));
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	int op=0;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		op+=c[i];
	}
	int r=rand();
	cout<<(r*op)%998244353;	
	return 0;
} 
