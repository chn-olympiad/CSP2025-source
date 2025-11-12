#include<bits/stdc++.h>
using namespace std;
long long tot=1,g;
int n,m,i,co;
char ch[505];
bool cmp(int a,int b){return a>b;}
const int MOD=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		if(ch[i]=='1'&&co==0){
			co=0;
		}
		else{
			co=1;
		}
	}
	for(int i=1;i<=n;i++){
		tot*=n;
		tot%=MOD;
	}
	if(co==0){
		cout<<tot;
	}
	else{
		cout<<0;
	}
	return 0;
}
