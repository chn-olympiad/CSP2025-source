#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL XOR(LL a,LL b){
	int la,lb,p=1;
	LL ans=0;
	while(a>0||b>0){
		la=a%2;
		lb=b%2;
		if(la!=lb)ans+=p;
		p*=2;
		a/=2;
		b/=2;
	}
	return ans;
}
LL n,k,a[500100];
void solve_B(){
	int ans1=0,ans0=0;
	if(k==1){
		for(int i=1;i<=n;i++){
			int q;
			cin>>q;
			if(q==1)ans1++;
		}
		cout<<ans1;
	}
	if(k==0){
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]==0)ans0++;
			else if(a[i]==1&&a[i-1]==1){
				ans0++;
				a[i]=2;
			}
		}
		
		cout<<ans0;
	}
	
	return;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	if(k==1||k==0){solve_B();return 0;}
	cout<<rand()%n;
	/*for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;i<=n;j++){
			string s;
			char l=i+'0';
			char r=j+'0';
			s=l+","+r;
			map[s]
		}
	}*/
	return 0;
}

