#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
int a[10005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,maxn=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==1){
		cout<<0;
	}
	if(n==2){
		cout<<0;
	}
	if(n==3){
		for(int i=1;i<=n;i++){
			if(a[i]>maxn){
				maxn=a[i];
			}
		}
		if(a[1]+a[2]+a[3]>maxn*2){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	cout.flush();
	return 0;
}
