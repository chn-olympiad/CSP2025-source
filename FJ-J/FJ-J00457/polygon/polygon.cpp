#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10,mod=998244353;
typedef long long ll;
int n,a[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=0,cnt=0;
	if(n==3){
		ans=max(a[1],max(a[2],a[3]));
		if((a[1]+a[2]+a[3])>(ans*2)){
			cout<<1;
			return 0;
		}else{
			cout<<0;
			return 0;
		}
	}
	if(n==4){
		cnt=0;
		ans=max(a[1],max(a[2],a[3]));
		if((a[1]+a[2]+a[3])>(ans*2)){
			cnt++;
		}
		ans=max(a[1],max(a[2],a[4]));
		if((a[1]+a[2]+a[4])>(ans*2)){
			cnt++;
		}
		ans=max(a[4],max(a[2],a[3]));
		if((a[1]+a[2]+a[3])>(ans*2)){
			cnt++;
		}
		ans=max(a[1],max(a[2],max(a[3],a[4])));
		if((a[1]+a[2]+a[3]+a[4])>(ans*2)){
			cnt++;
		}
		cout<<cnt;
		return 0;
	}
	cnt=0;
	for(int j=1;j<=n-3+1;j++){
		for(int i=j;i<=n-3+1;i++){
			ans=max(a[i],max(a[i+1],a[i+2]));
			if((a[i]+a[i+1]+a[i+2])>(ans*2)){
				cnt++;
			}
		}
	}
	for(int j=1;j<=n-4+1;j++){
		for(int i=j;i<=n-4+1;i++){
			ans=max(a[i],max(a[i+1],max(a[i+2],a[i+3])));
			if((a[i]+a[i+1]+a[i+2]+a[i+3])>(ans*2)){
				cnt++;
			}
		}
	}
	for(int j=1;j<=n-5+1;j++){
		for(int i=j;i<=n-5+1;i++){
			ans=max(a[i],max(a[i+1],max(a[i+2],max(a[i+3],a[i+4]))));
			if((a[i]+a[i+1]+a[i+2]+a[i+3]+a[i+4])>(ans*2)){
				cnt++;
			}
		}
	}
	for(int j=1;j<=n-6+1;j++){
		for(int i=j;i<=n-6+1;i++){
			ans=max(a[i],max(a[i+1],max(a[i+2],max(a[i+3],max(a[i+4],a[i+5])))));
			if((a[i]+a[i+1]+a[i+2]+a[i+3]+a[i+4]+a[i+5])>(ans*2)){
				cnt++;
			}
		}
	}
	for(int j=1;j<=n-7+1;j++){
		for(int i=j;i<=n-7+1;i++){
			ans=max(a[i],max(a[i+1],max(a[i+2],max(a[i+3],max(a[i+4],max(a[i+6],a[i+5]))))));
			if((a[i]+a[i+1]+a[i+2]+a[i+3]+a[i+4]+a[i+5]+a[i+6])>(ans*2)){
				cnt++;
			}
		}
	}
	for(int j=1;j<=n-8+1;j++){
		for(int i=j;i<=n-8+1;i++){
			ans=max(a[i],max(a[i+1],max(a[i+2],max(a[i+3],max(a[i+4],max(a[i+6],max(a[i+7],a[i+5])))))));
			if((a[i]+a[i+1]+a[i+2]+a[i+3]+a[i+4]+a[i+5]+a[i+6]+a[i+7])>(ans*2)){
				cnt++;
			}
		}
	}
	for(int j=1;j<=n-9+1;j++){
		for(int i=j;i<=n-9+1;i++){
			ans=max(a[i],max(a[i+1],max(a[i+2],max(a[i+3],max(a[i+4],max(a[i+6],max(a[i+7],max(a[i+8],a[i+5]))))))));
			if((a[i]+a[i+1]+a[i+2]+a[i+3]+a[i+4]+a[i+5]+a[i+6]+a[i+7]+a[i+8])>(ans*2)){
				cnt++;
			}
		}
	}
	for(int j=1;j<=n-10+1;j++){
		for(int i=j;i<=n-10+1;i++){
			ans=max(a[i],max(a[i+1],max(a[i+2],max(a[i+3],max(a[i+4],max(a[i+6],max(a[i+7],max(a[i+8],max(a[i+9],a[i+5])))))))));
			if((a[i]+a[i+1]+a[i+2]+a[i+3]+a[i+4]+a[i+5]+a[i+6]+a[i+7]+a[i+8]+a[i+9])>(ans*2)){
				cnt++;
			}
		}
	}
	cout<<cnt;
	return 0;
}

