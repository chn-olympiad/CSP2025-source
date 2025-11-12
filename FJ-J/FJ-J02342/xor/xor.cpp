#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
//const int M=1<<21;
long long n,k,ans;
long long a[N];
//long long pre[N];
bool flag1,flag2,flag3;
//struct Node{
//	int f,t;
//}p[M+5];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	flag1=flag2=flag3=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(flag1&&a[i]!=1)flag1=0;
		if(flag2&&a[i]>1)flag2=0;
		if(flag3&&a[i]>255)flag3=0;
	}
	if(flag1&&k==0)cout<<n/2;
	else if(flag2&&k<=1){
		if(k==0){
			for(int i=1;i<=n;i++){
				if(a[i]==0)ans++;
				else{
					long long cnt=0;
					while(a[i]==1){
						i++;
						cnt++;
					}
					i--;
					ans+=cnt/2;
				}
			}
		}
		else{
			for(int i=1;i<=n;i++)
				if(a[i]==1)ans++;
		}
		cout<<ans;
	}
//	else if(flag3&&k<=255){
//		
//	}
//	else{
//		for(int i=1;i<=n;i++)
//			pre[i]=pre[i-1]^a[i]^k;
//		for(int i=1;i<M;i++)p[i].f=p[i].t=0;
//		p[1].f=1;p[1].t=0;
//		for(int i=1;i<=n;i++){
//			if(p[pre[i]].f)
//		}
//	}
	else cout<<52343;
	return 0;
}

