#include<bits/stdc++.h>
using namespace std;
int n;
int num[50005];
int net[50005];
int ton[50005];
long long maxans=0;
void solve(int pre,int win);
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>num[i];
	}
	sort(num+1,num+1+n);
	net[1]=num[1];
	for (int i=2;i<=n;i++){
		
		net[i]=net[i-1]+num[i];
		if (net[i]>5000)net[i]=5001;
	}
	for (int i=3;i<=n;i++){
		solve(i,num[i]);
	}
	cout<<maxans;
	return 0;
}
void solve(int pre,int win){
	if (win<0){
		maxans=maxans%998244353;
		maxans++;
		maxans=maxans%998244353;
	}
	for (int i=pre-1;i>=1;i--){
		if (net[i]>win){
			solve(i,win-num[i]);
		}else{
			break;
		}
		
	}
}
