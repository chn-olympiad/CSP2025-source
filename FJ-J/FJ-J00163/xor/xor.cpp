#include<bits/stdc++.h>
using namespace std;
int n;
struct two{
	int n10;
	int n2[20];
};
two a[200005];
int ans;
int k;
int k20[20];
int cc1=1;
int ma=-1;
int main(){
	freopen("xor4.in","r",stdin);
	freopen("xor.out","w",stdout);
	//scanf("%d,%d",&n,&k);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i].n10;
		ma=max(ma,a[i].n10);
	}
	if(k<=1&&ma<=1){
		
		for(int i=1;i<=n;i++){
			if(a[i].n10==k) ans++;
			else if(a[i+1].n10!=k&&i+1<=n){
				ans++;
				i++;
				
			}
		}
	}else{
		for(int i=1;i<=n;i++){
			int cnt=0;
			while(a[i].n10!=0){
				a[i].n2[++cnt]=a[i].n10%2;
				a[i].n10/=2;
				
			}
		}
		if(1){
			int cnt=0;
			while(k!=0){
				k20[++cnt]=k%2;
				k/=2;
				
			}	
		}
		for(int i=1;i<=n;i++){
			int an[20]={0};
			for(int j=i;j>=cc1;j--){
				
				int f=1;
				for(int i20=1;i20<=20;i20++){
					if(j==i) an[i20]=a[j].n2[i20];
					else if(an[i20]==a[j].n2[i20]){
						an[i20]=0;
					}else{
						an[i20]=1;
					}
					if(an[i20]!=k20[i20]){
						f=0;
						
					}
					
				}
				if(f==1){
					cc1=i;
					ans++;
					break;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}






