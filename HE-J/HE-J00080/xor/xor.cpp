#include<bits/stdc++.h>
using namespace std;
const int INF=5*1e5+20;
int n,k;
int a[INF];
bool baoli(int x){
	int nx=a[1],ny=a[x+1];
	for(int i = 2 ;i<=x;i++){
		nx^=a[i];
	}
	for(int i=x+2;i<=n;i++){
		ny^=a[i];
	}
	if(nx+ny==k){
//		cout << nx <<" "<< ny<<endl;
		return true;
	}else{
//	cout << nx <<" "<< ny<<endl;
		return false;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	bool flag=0;
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0||a[i]==a[i-1]){
			flag=1;
			cnt++;
		}
	}
	if(k==0&&flag){
		cout<<cnt;
		return 0;
	}
	int rnt=0;
	for(int i = 1;i<=n;i++){
		if(baoli(i)==1){
			rnt++;
		}
	}
	cout<<rnt;
	return 0;
}


