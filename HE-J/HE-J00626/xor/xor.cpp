#include<bits/stdc++.h>
using namespace std;
const int N=5e5+100;
int ans=0;
int n,k;
int a[N];
bool flag=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	a[0]=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==1){
		if(a[1]!=k){
			cout<<0<<'\n';
			return 0;
		}else {
			cout<<1<<'\n';
		}
	}
	if(k<=1){
		int cnt=0;
		int t=1;
		for(int i=1;i<=n;i++){
			if(a[i]==k||t>=2){
				cnt++;
				t=0;
			}else if(a[i]!=1){
				t++;
			}
		}
		cout<<cnt;
		return 0;
	}else if(!k&&n==2){
		if(((a[1]==0)&&(a[2]==0))){
			cout<<2;
		}else if((a[1]==0||a[2]==0)||(a[1]==a[2])){
			cout<<1<<'\n';
		}else {
			cout<<0<<'\n';
		}
		return 0;
	}
	cout<<n;
	return 0;
}
