#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int N=509;
int n,m,c[N],a[N];
int id[N];
void init(){
	string str;
	cin>>n>>m>>str;
	for(int i=1;i<=n;i++){
		a[i]=str[i-1]-48;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	return;
}
bool check(){
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(cnt>=c[id[i]]){
			cnt++;
			continue;
		}
		if(!a[i]){
			cnt++;
			continue;
		}
	}
	return (n-cnt)>=m;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	init();
	for(int i=1;i<=n;i++){
		id[i]=i;
	}
	int cnt=0;
	do{
		cnt+=check();
		if(cnt>=mod){
			cnt-=mod;
		}
	}while(next_permutation(id+1,id+n+1));
	cout<<cnt<<endl;
	return 0;
}