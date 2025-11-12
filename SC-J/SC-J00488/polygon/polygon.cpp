#include<bits/stdc++.h>
#define ll long long
using namespace std;
int yuan[5005],er[5005],qian[5005];
int n;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int yi=0;
	for(int i=1;i<=n;i++){
		cin>>yuan[i];
		er[i]=2*yuan[i];
	}
	sort(yuan+1,yuan+n+1);
	sort(er+1,er+n+1);
	for(int i=1;i<=n;i++){
		yi+=yuan[i];
		qian[i]=yi;
	}
	//1:
	ll ans=0;
	for(int i=n;i>=1;i--){
		if(er[i]>=qian[i]) break;
		int x1=qian[i]-er[i];
		int flag=0;
		for(int j=1;j<=i;j++){
			if(qian[j]>=x1){
				flag=j-1;
				break;
			}
			flag=j;
		}
		if(flag==0){
			ans++;
			ans%=998244353;
			continue;	
		}
		else{
			ans+=pow(2,flag);
			ans%=998244353;
		}
	}
	ans%=998244353;
	//2:
	int x=n-3;
	for(int z=n;z>=1;z--){
		if(er[z]>=qian[z]) break;
		for(int y=z-1;y>x;){
			bool flag=0,m=0;
			for(x=y-1;x>=1;){
				if(yuan[x]==yuan[x-1]&&!m){
					if(x==1){
						break;
					}
					x--;
					continue;
				}
				m=0;
				if(qian[z]-qian[y]+qian[x]>er[z]){
					ans++; 
					ans%=998244353;
					if(x>1){
						x--;
					}
					else{
						y--;
						if(x==y){
							if(x==1){
								flag=1;
								break;
							}
							x--;
						}
						m=1;
					}
				}
				else{
					y--;
					if(x==y){
						if(x==1){
							flag=1;
							break;
						}
						x--;
						m=1;
					}
				}
			}
			if(flag){
				break; 
			} 
		}
	}
	cout<<ans;
	return 0;
} 