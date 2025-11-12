#include<iostream>
#include<string>
#include<cstring>
const int N=110;
int n,q,ans;
std::string t1,t2,s[N][2];
void check(int now,int x){
	for(int i=0;i<s[x][0].size()&&now+i<t1.size();i++){
		if(s[x][0][i]!=t1[now+i]){
			return;
		}
	}
	for(int i=0;i<now;i++){
		if(t1[i]!=t2[i]){
			return;
		}
	}
	for(int i=0;i<s[x][1].size();i++){
		if(s[x][1][i]!=t2[now+i]){
			return;
		}
	}
	for(int i=now+s[x][1].size();i<t1.size();i++){
		if(t1[i]!=t2[i]){
			return;
		}
	}
	ans++;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	std::cin>>n>>q;
	for(int i=1;i<=n;i++){
		std::cin>>s[i][0]>>s[i][1];
	}
	while(q--){
		std::cin>>t1>>t2;
		ans=0;
		if(t1.size()!=t2.size()){
			std::cout<<"0\n";
			continue;
		}
		for(int i=0;i<t1.size();i++){
			for(int j=1;j<=n;j++){
				check(i,j);
			}
		}
		std::cout<<ans<<"\n";
	}
	return 0;
}
/*
n,q<=100 L1,L2<=200
O(qnL1L2)
q=100 n=100 L1=200 L2=200 4e8
10
*/
