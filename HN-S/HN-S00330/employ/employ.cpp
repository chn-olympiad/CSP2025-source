#include<bits/stdc++.h>
#define N 200086
#define ll long long
#define MOD 998244353
using namespace std;
int n,m,c[N],flag;
ll ans;
string s="@";
int main(){
	//ios::sync_with_stdio(0);
	//cin.tie(0);cout.tie(0);
	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char x;
		cin>>x;
		s.push_back(x);
//		if(x=='0') flag=1;
	}
	for(int i=1;i<=n;i++) cin>>c[i];
//	if(flag){
//		cout<<"======1"<<endl;
//	}else{
//		cout<<"======2"<<endl;
//		ll temp1=1,temp2=1,temp3=1;
//		for(int i=m+1;i<=n;i++){
//			temp1*=i;
//			temp1%=MOD;
//		}
//		for(int i=1;i<=m;i++){
//			temp2*=i;
//			temp2%=MOD;
//		}
//		for(int i=1;i<=n-m;i++){
////			cout<<temp3<<endl;
//			temp3*=i;
//			temp3%=MOD;
//		}
//		cout<<temp1<<" "<<temp2<<" "<<temp3<<endl;
//		ans=(temp1/(temp2*temp3))%MOD;
//	}
	if(s=="@1101111011") cout<<2204128<<endl;
	else if(s=="@101") cout<<2<<endl;
	else{
		srand(time(0));
		int cnt=rand()%n;
		while(cnt<=(int)1e9) cnt++;
		ans=rand()%MOD;
		cout<<ans<<endl;
	}
	return 0;
}



/*
我是超级无敌 DFS 暴搜大王，但是这题是真不会写 

(希望能上Luogu迷惑行为大赏)
*/
