#include<bits/stdc++.h>
using namespace std;
const int N=1e5+8;

int st[N],num[N];

int main(){
	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int ans=0;
	int k; 
	cin>>k;
	
	for(int i=1;i<=k;i++){
		cin>>num[i];
		
	}
	
	sort(num,num+k);

	for(int i=k;i>=3;i--){
		for(int j=i-2;j>=1;j--){
			int x=0,ma=num[i];
				
			for(int z=j;z<=i;z++){
				x+=num[z];
				
			}
		
			if(x>(2*ma)&&(i-j+1)>=3){
				
				ans++;
				long long p=1;
				for(int z=1;z<=j;z++){
					p*=z;
					p%=998;
					p%=244;
					p%=353;
			
				}
				ans+=p;
			
				ans%=998;
				ans%=244;
				ans%=353;
				
			}
			
		}
	}
	cout<<ans;
	return 0;
} 