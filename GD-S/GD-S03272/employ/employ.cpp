#include<bits/stdc++.h>
using namespace std;
const int P=998244353;
int n,m,p[505],c[505];
long long ans;
string s;
bool judge[505];
void dfs(int front,int now,int last){
	if(now>m){
		return;
	}
	else if(now==m){
		int sum=1;
		for(int i=2;i<=last;i++){
			sum*=i;
			sum%=P;
		}
		ans+=sum;
		ans%=P;
	}
	else{
		for(int i=1;i<=n;i++){
			if(judge[i]||front>c[i]){
				continue;
			}
			else{
				if(s[n-last+1]=='0'){
					judge[i]=true;
					dfs(front+1,now,last-1);
					judge[i]=false;
				}
				else{
					judge[i]=true;
					dfs(front,now+1,last-1);
					judge[i]=false;
				}
			}
		}
	}
	return;
}
int main(){
	ifstream read("employ.in");
	ofstream write("employ.out");
	read>>n>>m>>s;
	for(int i=1;i<=n;i++){
		read>>c[i];
	} 
	bool b=1;
	for(int i=0;i<(int)s.length();i++){
		if(s[i]!='1'){
			b=0;
			break;
		}
	}
	if(b){
		ans=1;
		for(int i=n;i>m;i--){
			ans*=i;
			ans%=P;
		}
		write<<ans;
	}
	else{
		dfs(0,0,n);
		write<<ans%P;
	}
	return 0;
}
