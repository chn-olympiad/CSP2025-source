#include<bits/stdc++.h>
using namespace std;
//Ren5Jie4Di4Ling5%
struct w{
	int a;
	int b;
	int c;
};
int n;
long long int maxn=-1;
w s[100005];
void f(int a1,int b1,int c1,int i,int num){
	if(a1+b1+c1==n){
		if(maxn<num){
			maxn=num;
		}
		return;
	}
	else{
		if(a1<n/2){
			f(a1+1,b1,c1,i+1,num+s[i+1].a);
		}
		if(b1<n/2){
			f(a1,b1+1,c1,i+1,num+s[i+1].b);
		}
		if(c1<n/2){
			f(a1,b1,c1+1,i+1,num+s[i+1].c);
		}
	}
}
int dp[100005][5]={0};
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		//cout<<48236462384<<endl;
		
		cin>>n;
		int k=n/2;
		memset(s,0,sizeof(s));
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++){
			cin>>s[i].a>>s[i].b>>s[i].c;
		}
		maxn=-1;
		int flag=0;
		for(int i=1;i<=n;i++){
			if(s[i].b!=0&&s[i].c!=0){
				flag=1;
			}
		}
		if(flag==0){
//			cout<<327482394623946823<<endl;
			int bo[30000];
			for(int i=1;i<=n;i++){
				bo[s[i].a]++;
			}
			int q=1;
			int e=20001;
			long long int sum=0;
			while(q<=k){
				e--;
				while(bo[e]!=0){
					bo[e]--;
					sum+=e;
					q++;
				}
			}
			cout<<sum;
			return 0;
		}
		f(0,0,0,0,0);
		cout<<maxn;
	}
	return 0;
}




//#include<bits/stdc++.h>
//using namespace std;
////Ren5Jie4Di4Ling5%
//struct w{
//	int a;
//	int b;
//	int c;
//};
//w s[100005];
//int dp[100005][5]={0};
//int main(){
//	//freopen("club.in","r",stdin);
//	//freopen("club.out","w",stdout);
//	int T;
//	cin>>T;
//	while(T--){
//		//cout<<48236462384<<endl;
//		int n;
//		cin>>n;
//		int k=n/2;
//		memset(s,0,sizeof(s));
//		memset(dp,0,sizeof(dp));
//		for(int i=1;i<=n;i++){
//			cin>>s[i].a>>s[i].b>>s[i].c;
//		}
//		//cout<<64264682468234786237864873<<endl;
//		int a1=0,b1=0,c1=0;
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=3;j++){
//				a[i][j]=max(a[i][j],a[i][j]+s[i].a)
//					
//				//cout<<721867812648263472<<endl;
//			}
//		}
//		for(int i=1;i<=n;i++){
//			for(int j=n;j>=k;j--){
//				cout<<dp[i][j]<<' ';
//			}
//			cout<<endl;
//		}
//		cout<<dp[3][n];
//	}
//	return 0;
//}
//
//
//
//



