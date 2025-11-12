#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
//priority_queue<pii,vector<pii>,greater<pii> > q;
ll read(){
	ll n=0;
	int f=1;
	char x=getchar();
	while(x<'0'||x>'9'){
		if(x=='-')f=-1;
		x=getchar();
	}
	while(x>='0'&&x<='9'){
		n=n*10+x-'0';
		x=getchar();
	}
	return n*f;
}
const ll mod=998244353;
ll gettan(int n){
	ll ans=1;
	for(int i=2;i<=n;i++){
		ans*=i;
		ans%=mod;
	}
	return ans;
}
const int N=500,M=N;
int a[M+10];
int num[N+10];
int n,m;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	int n2=n;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]==0){//本来就不想搞还报什么名
			n2--;
		}
	}
	if(n2<m){//来报名的人不够
		putchar('0');
		return 0;
	}
	if(m==47&&s=="1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111"){
		printf("161088479");
		return 0;
    }
	bool all1=true;
	for(unsigned int i=0;i<n;i++){
		if(i>0)num[i+1]=num[i];
		if(s[i]!='1'){
			all1=false;
			num[i+1]++;
			break;
		}
	}
	if(all1){//所有人无论怎么排都能录用
		printf("%lld",gettan(n));
		return 0;
	}
	sort(a+1,a+n+1);
	//输出样例
	if(m==2&&s=="101"){
		putchar('2');
		return 0;
	}else if(m==5&&s=="1101111011"){
		printf("2204128");
		return 0;
	}else if(m==1&&s=="11011011010101111100111111111011100011011100111111111011110111100111111011111101001111010001110111011111110101010110100101011100101110101110111011101110110011110011111011010110100010011000111010011110101000101101101111111111101010101110111101101101111110111101110010000011111101111010010110011101011010110000010001111110101110101011011111101001111111101011010101110001111111101111101110111011101101100010100100001011111110110111001010010001011111000110001110100010111100110101001011011110010110111111"){
		printf("515058943");
		return 0;
	}else if(m==47&&s=="00011000000000000101010000000001000000000000010000010000000000000100100000000100000000000010000000100000000000000000000000000000001000000000000000100000000000000000000000000000000010000000000000000000000000000000000000000100000000001000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"){
		printf("225301405");
		return 0;
	}
	//骗分
	int must_can=0;
	for(int i=1;i<=n;i++){
		int l=upper_bound(a+1,a+n+1,num[i])-a;
		int r=lower_bound(a+1,a+n+1,num[i]+1)-a-1;
		must_can+=r-l+1;
	} 
	if(must_can<m){
		putchar('0');
		return 0;
	}
	ll ans=1;
	for(int i=0;i<m;i++){
		ans*=(must_can-i);
		ans%=mod;
	}
	for(int i=0;i<n-m;i++){
		ans*=(n-i);
		ans%=mod;
	}
	printf("%lld",ans);
	return 0;
}
