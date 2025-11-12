//GZ-S00332 贵州省实验中学 王满霖
#include<bits/stdc++.h>
using namespace std;
int dp[100010][4];
int sb[5];
struct sbb{
	int a,b,c;
	int ab,ac,bc;
}aa[100010];
bool cmp(sbb aaa,sbb bbb){
	if(aaa.a==bbb.a){
		if(aaa.b==bbb.b){
			return aaa.c>=bbb.c;
		}
		return aaa.b>bbb.b;
	}
	return aaa.a>bbb.a;
}
int main(){
	freopen("club.in","w",stdin);
	freopen("club.out","r",stdout);
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		for(int i=1;i<=n;i++){
			cin>>aa[i].a>>aa[i].b>>aa[i].c;
			aa[i].ab=abs(aa[i].a-aa[i].b);
			aa[i].ac=abs(aa[i].a-aa[i].c);
			aa[i].bc=abs(aa[i].b-aa[i].c);
		}
		sort(aa+1,aa+n+1,cmp);
		for(int i=1;i<=n;i++){
			cout<<aa[i].a<<' '<<aa[i].b<<' '<<aa[i].c<<'\n';
		}
		
		//for(int i=1;i<=n;i++){
		//	cin>>sb[1]>>sb[2]>>sb[3];
		//	for(int j=1;j<=3;j++){
	//			dp[i][j]=sb[j]+max(dp[i-1][1],max(dp[i-1][2],dp[i-1][3]));
		//	}
	//	}
	//	int sum=0;
	//	for(int i=1;i<=3;i++){
	//		sum+=dp[n][i];
	//	}
	//	cout<<sum<<"\n";
	}
	while(1){
		while(1){
			while(1) cout<<1.3;
		}
	}
	return 0;
} 
