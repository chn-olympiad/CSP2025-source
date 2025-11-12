#include<bits/stdc++.h>
using namespace std;
const int MAXN=505,MOD=998244353;
int n,m;
int diff[MAXN],c[MAXN];
string s;
void process(){
	for()
} 
int main(){
	ios::sync_with_stdio(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s=" "+s;
	for(int i=1;i<=n;++i){
		diff[i]=s[i]-48;
	}
	for(int i=1;i<=n;++i){
		cin>>c[i];
	}
	
	for()
	if(m==1){
		int cnt=0,wa=0;
		for(int i=1;i<=n;++i){
			if(diff[i]==0){//不能录用 
				wa++;
			}
			else if(wa>=c[i]){//将放弃参加面试
				wa++;
			}
			else{
				cnt++;
			} 
		}
		if(cnt>=1){
			
		}
	}
	int cnt=0,wa=0;
	for(int i=1;i<=n;++i){
		if(diff[i]==0){//不能录用 
			wa++;
		}
		else if(wa>=c[i]){//将放弃参加面试
			wa++;
		}
		else{
			cnt++;
		} 
	}
	if(cnt>=m){
		cout<<"y";
	}
//	for(int i=1;i<=si;++i){
//		cout<<c[i]<<" ";
//	}
	return 0;
}
