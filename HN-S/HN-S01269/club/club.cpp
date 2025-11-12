#include<bits/stdc++.h>
using namespace std;
int t,n,z;
const int N=1e4+5;
struct hm{
	int a;
	int b;
	int c;
};
struct ans{
	int ma;
	int mb;
	int mc;
	int v;
	int te;
	int d;
};
bool cmp(ans x,ans y){
	return x.ma>y.ma;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		z=0;
		cin>>n;
		hm s[N];
		ans an[N];
//		for(int i=1;i<=3;i++){
//			for(int j=1;j<=n/2;j++){
//			if()dp[i][j]=max(dp[i-1][j]+a[k][i],dp[i][j])
//				}
//			}
//		}
//			for(int i=1;i<=n;i++){// 第几个人 
//				for(int j=1;j<=3;j++){// 第几个部门				        
//				if(m[j]+1<=n/2){
//				dp[i][j]=max(dp[i-1][j]+a[i][j],dp[i-1]);	
//					}else{
//					dp[i]=dp[i][j-1];
//				}
//					
//					}	
//				} 
//			}
		for(int i=0;i<n;i++){
			cin>>s[i].a>>s[i].b>>s[i].c;	
		    an[i].ma=max(s[i].a,max(s[i].b,s[i].c));
		    an[i].v=i;
		    if(an[i].ma==s[i].a){
		    	an[i].te=0;
			}else if(an[i].ma==s[i].b){
		   		an[i].te=1;		 	
			}else if(an[i].ma==s[i].c){
		   		an[i].te=2;	
			}
		}
		sort(an,an+n,cmp);
		int sum[3]={0,0,0};
		for(int j=0;j<n;j++){
			if(an[j].d==0&&sum[an[j].te]+1<=n/2){
				an[j].d==1;
				sum[an[j].te]++;
				z+=an[j].ma;
			}
		}
	
	cout<<z<<"\n";
}

	return 0;
} 
//Ren5Jie4Di4Ling5%
//3
//4
//4 2 1
//3 2 4
//5 3 4
//3 5 1
//4
//0 1 0
//0 1 0
//0 2 0
//0 2 0
//2
//10 9 8
//4 0 0
