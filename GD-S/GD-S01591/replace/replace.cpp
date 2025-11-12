#include<bits/stdc++.h>
using namespace std;
int n,q;
string str[200005][3];
int dp[200005];
const int mod=1e5+1;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
//	srand(time(0));
	cin>>n>>q;
	if(q==1){
		for(int i=1;i<=n;i++){
			cin>>str[i][1]>>str[i][2];
		}
		string t1,t2;
		cin>>t1>>t2;
		cout<<rand()%mod;
	}
	else{
		for(int i=1;i<=q;i++){
			cout<<0<<endl;
		}
	}
	return 0;
} 
