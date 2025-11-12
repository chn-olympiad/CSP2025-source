#include<bits/stdc++.h>
using namespace std;
int t,a[100005][3],n,jl[3];
int ans=0,cnt;
void f(int now){
	if(now==n+1){
		cnt=max(cnt,ans);
	}
	for(int i=0;i<3;i++){
		if(jl[i]==n/2)continue;
		jl[i]++;
		ans+=a[now][i];
		f(now+1);
		ans-=a[now][i];
		jl[i]--;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	cin>>t;
	while(t--){
		cnt=-1;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
		}
		f(1);
		cout<<cnt<<'\n';
	}
	return 0;
}