#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n;
priority_queue<int,vector<int>,greater<int> > ta,at;
long long dp[210][210][210];
//long long pd[]
struct node{
	int a,b,c;
}num[N];
bool cmp(node a,node b){
	if(a.a!=b.a)return a.a>b.a;
	return a.b>b.b;
}
bool pmc(node a,node b){
	if(a.b!=b.b)return a.b>b.b;
	return a.a>b.a;
}
void so4(){
	memset(dp,0,sizeof(dp));
	long long ans=0;
	for(int i = 0;i<=n;i++){
		for(int j = 0;j<=i;j++){
			if(j>n/2)break;
			for(int p = 0;p<=i-j;p++){
				int s=i-j-p;
				if(s<0)break;
				if(p>n/2)break;
				if(s>n/2)continue;
				if(j>0&&j<=n/2){
					dp[j][p][s]=max(dp[j][p][s],dp[j-1][p][s]+num[i].a);
					
				}
				if(p>0&&p<=n/2){
					dp[j][p][s]=max(dp[j][p][s],dp[j][p-1][s]+num[i].b);
				}
				if(s>0&&s<=n/2){
					dp[j][p][s]=max(dp[j][p][s],dp[j][p][s-1]+num[i].c);
				}
				ans = max(dp[j][p][s],ans);
			}
		}
	}
	cout<<ans<<"\n";
}
void so2(){
	for(int i = 1;i<=n;i++){
		ta.push(num[i].a);
		at.push(num[i].b);
		while(ta.size()>(n/2))ta.pop();
		while(at.size()>(n/2))at.pop();
	}
	long long ans=0;
	while(ta.size()){
		ans+=ta.top();
		ta.pop();
	
	}
	long long an=0;
	while(at.size()){
		an+=at.top();
		at.pop();
	
	}
	int lc=0,rc=0;
	long long da=0;
	if(an>ans){
		sort(num+1,num+1+n,pmc);
		for(int i = 1;i<=n;i++){
			if(num[i].a>num[i].b&&lc<n/2){
	//			cout<<1<<" ";
				lc++;
				da+=num[i].a;
			}else if(rc<n/2){
	//			cout<<2<<" ";
				rc++;
				da+=num[i].b;
			}
		}
		
		cout<<da<<"\n";
	}else{
		sort(num+1,num+1+n,cmp);
		for(int i = 1;i<=n;i++){
			if(num[i].a>num[i].b&&lc<n/2){
	//			cout<<1<<" ";
				lc++;
				da+=num[i].a;
			}else if(rc<n/2){
	//			cout<<2<<" ";
				rc++;
				da+=num[i].b;
			}
		}
		cout<<da<<"\n";
	}
}
void so(){
	int flag=0;
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>num[i].a;
		cin>>num[i].b;
		cin>>num[i].c;
//		if(num[i].b!=0){
//			flag=10;
//		}
		if(num[i].c!=0&&num[i].b!=0)flag=10;
	//	cout<<num[i].a<<" "<<num[i].b<<" "<<num[i].c<<"\n";
		if(num[i].c==0){
			
			if(num[i].b==0){
				if(flag<=1){
				//	cout<<"ok\n";
					flag=1;
				}
			}else{
				if(flag<=2){
					flag=2;
				}
			}
		}
	//	cout<<num[i].a<<" "<<num[i].b<<" "<<num[i].c<<" "<<flag<<"\n";
	}
	//flag=0;
//	cout<<flag<<"\n";
	if(flag==1){
	//	cout<<flag<<"\n";
		for(int i = 1;i<=n;i++){
			ta.push(num[i].a);
			while(ta.size()>(n/2))ta.pop();
		}
		long long ans=0;
		while(ta.size()){
			ans+=ta.top();
			ta.pop();
		}
		cout<<ans<<"\n";
		return;
	}else{
		so4();
	}
//	if(flag==2){
//		so2();
//	}
//	if(flag==10){
//		so4();
//	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int t;
	cin>>t;
	while(t--){
		so();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
