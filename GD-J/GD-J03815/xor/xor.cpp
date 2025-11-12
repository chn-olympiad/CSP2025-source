#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+7;
long long n,k,a[MAXN],prea[MAXN],ert=0,dp[MAXN];

int XO(long long a,long long b){
	long long ans=0;
	queue<long long> q1;
	queue<long long> q2;
	string s="";
//	cout<<"a:"<<a<<" "<<"b:"<<b<<endl;
	if(a==0)q1.push(0);
	else
	while(a>0){
		q1.push(a%2);
		a/=2;
	}
	if(b==0)q2.push(0);
	else
	while(b>0){
		q2.push(b%2);
		b/=2;
	}
//	cout<<"q1:"<<q1.front()<<" "<<"q2:"<<q2.front()<<endl;
//	cout<<"s:"<<s<<endl;
	int len=min(q1.size(),q2.size());
	while(len--){
		long long a1=q1.front(),b1=q2.front();
		if(a1==1&&b1==0)s+='1';
		if(a1==0&&b1==0)s+='0';
		if(a1==1&&b1==1)s+='0';
		if(a1==0&&b1==1)s+='1';
		q1.pop(),q2.pop();
	}
//	cout<<"s:"<<s<<endl;
	if(!q1.empty()){
		while(!q1.empty()){
			long long a1=q1.front();
			if(a1==1)s+='1';
			else s+='0';
			q1.pop();
		}
	}
	
	else if(!q2.empty()){
		while(!q2.empty()){
			long long a1=q2.front();
			if(a1==1)s+='1';
			else s+='0';
			q2.pop();
		}
	}
//	cout<<"s:"<<s<<endl;
//	cout<<"ans:"<<ans<<endl;
	for(int i=0;i<s.size();i++){
		ans+=(s[i]-'0')*pow(2,s.size()-1-i);
	//	cout<<s[i]<<" "<<pow(2,s.size()-1-i)<<" "<<ans<<endl;
	}
	return ans;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	if(n==1&&k==0){
		if(a[1]!=0)printf("0");
		else printf("1");
	}
	if(n==2&&k==0){
		int yu=0;
		if(XO(a[1],a[2])==k)yu++;
		if(a[1]==k)yu++;
		if(a[2]==k)yu++;
		printf("%d",yu);
	}
	else{//³£¹æ 
		prea[1]=a[1];
		for(int i=2;i<=n;i++){
			prea[i]=XO(a[i],prea[i-1]);
		}
////		for(int i=1;i<=n;i++){
////			printf("%lld ",prea[i]); 
////		}
//		cout<<'\n';
		for(int l=1;l<=n;l++){
			for(int r=l;r<=n;r++){
				dp[r]=dp[l];
				if(a[r]==k&&l==r&&l<=n&&r<=n){
					dp[r]=max(dp[r],dp[l-1]+1);
				}
				if(abs(prea[r]-prea[l-1])==k&&l<=n&&r<=n){
					dp[r]=max(dp[r],dp[l-1]+1);
					l=r;
				}
			}
		}
			

//		while(l<=r&&l<=n){
//			if(r==n+1)l++,r=l;
//			if(abs(prea[r]-prea[l-1])==k&&l<=n&&r<=n){
//		//		cout<<l<<" "<<r<<endl;
//				l=r;ert++;
//			}
//			else if(a[r]==k&&l==r&&l<=n&&r<=n){
//		//		cout<<l<<" "<<r<<endl;
//				l=r;ert++;
//			}
//			r++;
//		}
		printf("%lld",dp[n]);
	}

	//priority
	return 0;
}
