#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500005];
int b[500005];
int zuowei;
int ans;
int n,k;
void fen5(){
		if(n==1){
			if(a[1]==k)cout<<1;
			else cout<<0;
			return ;
		}
		if(n==2)
		if(k==0){
			if(a[1]==0)ans++;
			if(a[2]==0)ans++;
//			if(a[1]=0&&a[2]!=0){
//				if(a[1]==a[2])ans++;
//			}
			cout<<ans;
			return ;
		}
}
void fen10(){
	bool f=1;
	int now=0;
	for(int i=1;i<=n;i++){
		if(a[i]!=1)f=0;
	}
	if(f==1){
		cout<<0;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(a[i]==0)ans++;
//		else{
//			if(a[i]==a[i-1]){
//				ans++;
//				a[i]=1e6+17;
//			}
//		}
	}
	cout<<ans;
	return ;
}
void fen15(){
	for(int i=1;i<=n;i++){
		if(a[i]==1)ans++;
//		else{
//			if(a[i]==a[i-1]){
//				ans++;
//				a[i]=-1e3+n+ans+i;
//			}
//		}
	}cout<<ans;
	return ;
}
void pianfen(){
	int now=0,bj=0;
	for(int i=1;i<=n;i++){
		if(a[i]==k){
		ans++;	
		now=0;
		}
		else{
			now++;
			for(int j=i-1;j>=i-now;j--){
				b[i]^=a[j];
				if(b[i]==k){
				ans++;	
				a[i]=-1e3+17+i+ans;
				break;
				}
			}b[i]=a[i];
		}
	}
	cout<<ans;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
//	ios::sync_with_stdio(0);
//	std::cin.tie(0);
//    std::cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	if(n<=2){
		fen5();
		return 0;
	}
	else{
		if(k==0){
			fen10();
			return 0;
		}
		if(k==1){
			fen15();
			return 0;
		}
		else{
			pianfen();
			return 0;
		}
	}
	
	for(int i=1;i<=n;i++){
		if(a[i]==k)ans++;
	}
	
	return 0;
}//insert([]);
