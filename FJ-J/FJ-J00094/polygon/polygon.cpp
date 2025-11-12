#include<bits/stdc++.h>
#include<algorithm>
#include<cstdio>
using namespace std;

int stk[5005];

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.ans","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,ma,ans=0,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>stk[i];
	}
	sort(stk+1,stk+n+1);
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			sum=0,ma=-1;
			if(j-i<2) continue;
			for(int k=i;k<=j;k++){
				cout<<stk[k]<<" ";
				sum+=stk[k];
				ma=max(ma,stk[k]);
			}
			//cout<<"      sum:"<<sum<<" ma:"<<ma;
			if(ma*2<sum) ans++;
			cout<<endl;
		}
	}
	cout<<ans;
	return 0;
}
