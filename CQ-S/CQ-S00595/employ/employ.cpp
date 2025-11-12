/*
对于每个人都会有一个最晚的面试时间 
dp[i][k]在i号区间内 使得有k个人被录用的方案数
区间的分法：
1走一个
0走一个 
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=505;
//int refuse[N];
//int last_day[N];
//int dp[N][N];
//int len[N]; 
//int po[N];
int peo[N];
char cc[N];
bool vis[N];
int n,k;
int num[N];
int ans=0;
void f(int a){
	if(a==n+1){
		int gp=0;
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(cc[i]=='0'){
				gp++;
			}else{
				if(gp<peo[num[i]]){
					cnt++;
				}else{
					gp++;
				}
			}
		}
		if(cnt>=k){
			ans=(ans+1)%998244353;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			num[a]=i;
			f(a+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
//	cout<<18;
	cin>>n>>k;
	int cnt=0;
	int strc=-1;
	bool ch=0; 
	int la=0;
	bool fir=0;//第一块的样子
	for(int i=1;i<=n;i++){
		cin>>cc[i];
//		int c=cc[i]-'0';
//		if(!c){
//			refuse[++cnt]=i;
//		}
//		if(strc==-1){
//			strc=0;
//			ch=c,la=0;
//			fir=c;
//		}
//		if(ch!=c){
//			strc++;
//			len[strc]=i-la-1;
//			ch=c,la=i-1;
//		}
//		po[i]=strc;
	}
//	if(cc[n]==cc[n-1]){
//		len[strc]++;
//	}else{
//		len[++strc]=1;
//	}
//	
//	if(strc%2==1){
//		fir=-fir;
//	}
//	int mlast=strc;
//	if(!fir){
//		mlast=strc-1;
//	}
	for(int i=1;i<=n;i++){
		int c;
		cin>>peo[i];
//		if(c==0){
//			last_day[i]=0;
//		}else if(c<=cnt){
//			last_day[i]=po[refuse[c]];
//		}else{
//			last_day[i]=mlast;
//		}
	}
//	sort(last_day+1,last_day+n+1);
//	for(int i=1;i<=strc;i++){
//		int p=fir;//代表该段是否淘汰
//		if(i%2==1){
//			p=-p;
//		} 
//		if(p==1){
//			for(int j=1;j<=len[strc];j++){
//				
//			}
//		}
//	}
	f(1);
	cout<<ans;
	return 0;
}
/*
10 5
1101111011
6  0 4  2 1 2 5  4  3  3
10 0 10 7 2 7 10 10 10 10
*/ 
