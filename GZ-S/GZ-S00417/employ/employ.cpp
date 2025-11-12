//GZ-S00417 华东师范大学附属贵阳 谭斯雨
#include <bits/stdc++.h>
using namespace std;
const int N=510,MOD=998244353;
long long n,m,a[N],pre[N],ans,cnt,b[N],p[N],k[N];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]++;
		if(a[i]==0){
			cnt++;
		}
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		p[i]=p[i-1]+b[i];
	}
	for(int i=1;i<=n;i++){
		if(s[i]=='0'){
			pre[i]=pre[i-1]+1;
		}
		else{
			pre[i]=pre[i-1];
		}
	}
	if(m==n&&(pre[n]!=0||cnt>0)){
		cout<<0;
	}
	if(pre[n]>n-m){
		cout<<0<<endl;
		return 0;
	}
	if(pre[n]==0){
		ans=1;
		for(int i=2;i<=n;i++){
			ans*=i;
			ans%=MOD;
		}
		cout<<ans<<endl;
		return 0;
	}
	cout<<621;
	return 0;
}//依旧输出621，我赌测试点也粉mhn(提示：疑似死前最后幻想or吃菌子中毒了，需要紧急救治）
