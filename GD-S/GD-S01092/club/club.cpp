#include <bits/stdc++.h>
using namespace std;
long long t,n,a[10000][10000];
int cnt = 0,ct = 0,num = 0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
vector<int> b,c,d;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i = 0;i<n;i++) cin>>a[i][0]>>a[i][1]>>a[i][2];
	}
	for(int i = 0;i<n;i++){
		int maxn = max(a[i][0],a[i][1]);
		if(a[i][0]>a[i][1]) 
			max(a[i][0],a[i][1]); 
		if(a[i][0]<a[i][1]) 
			max(a[i][2],a[i][1]); 
		if(maxn == a[i][0]) 
			cnt++;
		else if(maxn == a[i][1]) 
			ct++;
		else 
			num++;
	}
		while(t--){
			for(int i = 0;i<n;i++){
				cout<<a[i][0]+a[i][1]+a[i][2];
				return 0;
			}
		}
	return 0;
}
