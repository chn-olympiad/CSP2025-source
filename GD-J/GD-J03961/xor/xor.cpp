#include<bits/stdc++.h>
using namespace std;
int n,k,a[500007],num[27],ans,sum[27],shu,p,tail=1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int j=1;j<=20;j++){
		if((k>>(j-1))&1){
			sum[j]++;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		shu^=a[i];
		if(shu==k){
			tail=i+1;
			ans++;
			shu=0;
			memset(num,0,sizeof(num));
			continue;
		}
		for(int j=1;j<=20;j++){
			if((a[i]>>(j-1))&1){
				num[j]++;
			}
		}
		while(tail<i){
			p=0;
			for(int j=1;j<=20;j++){
				if((a[tail]>>(j-1))&1){
					num[j]--;
				}
			}
			for(int j=1;j<=20;j++){
				if(sum[j]>0 and num[j]==0){
					p++;
					break;
				}
			}
			if(p>0){
				for(int j=1;j<=20;j++){
					if((a[tail]>>(j-1))&1){
						num[j]++;
					}
				}
				break;
			}
			tail++;
			shu^=a[tail-1];
			if(shu==k){
				tail=i+1;
				ans++;
				shu=0;
				memset(num,0,sizeof(num));
				break;
			}
		}
	}
	cout<<ans;
	return 0;
} 
