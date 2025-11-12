#include<bits/stdc++.h> 
using namespace std;
const int N=1e6+50000;
int dp[1010][1010];//区间i~j的权值 
int n,k,arr[N],R=-1;
long long ans=0;;
struct node{
	int l,r;
};
vector<node> v;
bool cmp(node x,node y){
	return x.r<y.r;
}
void init(){//预处理所有权值为k的区间 
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(i==j) dp[i][j]=arr[i];
			else dp[i][j]=(dp[i][j-1]^arr[j]);
		} 
	} 
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(dp[i][j]==k){
			//	cout<<"["<<i<<","<<j<<"] "<<dp[i][j]<<'\n';	
				node tmp; 
				tmp.l=i; tmp.r=j;
				v.push_back(tmp);
			}
		}
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n>>k;
	int sum1=0;
	bool flag=true;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		if(arr[i]>1) flag=false;
		if(arr[i]==1) sum1++;
	}
	if(flag==true&&k==1){ //全部a[i]都是小于等于1的 
		if(k==1) cout<<sum1<<" ";
		return 0; 
		//else cout<<n-sum1<<" "; 0的情况不同的 偶数的1也可以弄出来0 
	}
	init();
	sort(v.begin(),v.end(),cmp);
	int len=v.size();
	for(int i=0;i<len;i++){
		if(v[i].l>R){
			ans++;
			R=v[i].r;
		}
	//	cout<<v[i].l<<" "<<v[i].r<<'\n';
	} 
	cout<<ans;
	return 0;
}
//#Shang4Shan3Ruo6Shui4

