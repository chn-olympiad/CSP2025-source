#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
long long int t,n,a[100001][4],cun[100001],cnt[100001],jl1[100001],jl2,jl3,ans,ch;
cin>>t;
while(t--){
	cin>>n;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=3;j++){
			cin>>a[i][j];
		}
		if(a[i][2]==0)jl2++;
		else if(a[i][3]==0)jl3++;
		else if(a[i][1]==a[i][2]&&a[i][2]==a[i][3])ans++;
		cun[i] = a[i][2];
		cnt[i] = a[i][3];
	}
	if(jl2==n&&jl3==n){
		sort(cun+1,cun+1+n);
		for(int i = n;i>=n/2;i++)ch+=cun[i];
		cout<<ch<<endl;
	}else if(jl3==n){
		for(int i = 1;i<=n;i++){
			ch+=max(cun[i],cnt[i]);
		}
		cout<<ch<<endl;
	}else if(n==2){
		ch = max(a[1][1]+a[2][2],a[1][1]+a[2][3]);
		ch = max(max(a[1][2]+a[2][1],a[1][2]+a[2][3]),ch);
		ch = max(max(a[1][3]+a[2][1],a[1][3]+a[2][2]),ch);
		cout<<ch<<endl;
	}else{
		ch = a[1][1]*n;
		cout<<ch<<endl;
	}
	ch = jl2 = jl3 = ans = 0;
	
}
return 0;
}
