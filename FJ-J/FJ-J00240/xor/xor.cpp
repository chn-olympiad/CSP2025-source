#include<bits/stdc++.h>
using namespace std;
int flag1=1,flag2=1,flag3=1,n,k,a[500005],b[500005][25],d[26],ans=0,tot[500005],s=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			flag1=0;
		}
		if(a[i]!=1&&a[i]!=0){
			flag2=0;
		}
		if(a[i]==k){
			tot[++s]=i;
		}else if(a[i]!=k){
			flag3=0;
		}
	}
	ans-=s;
	if(flag1==1&&k==0){
		cout<<n/2;
		return 0;
	}else if(flag2==1){
		if(k==1){
			for(int i=1;i<=n;i++){
				if(a[i]==1){
					ans++;
				}
			}
			cout<<ans;
			return 0;
		}else if(k==0){
			int w1=0;
			for(int i=1;i<=n;i++){
				if(a[i]==0){
					ans++;
				}else if(a[i]==1&&w1==0){
					w1=i;
				}else if(a[i]==1&&w1!=0){
					if(i-w1==1){
						ans++;
						w1=0;
					}else{
						w1=i;
					}
				}
			}
			cout<<ans;
			return 0;
		}
	}else if(flag3==1){
		cout<<n;
		return 0;
	}
	for(int i=1;i<=n;i++){
		int m=a[i],gs=0;
		while(m!=0){
			gs++;
			b[i][gs]=m%2;
			m=m/2;
		}
		b[i][0]=gs;
	}
	int gs=0;
	while(k!=0){
		gs++;
		d[gs]=k%2;
		k=k/2;
	}
	d[0]=gs;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int bj=1;
			for(int z=1;z<=s;z++){
				if(i<=tot[z]&&j>=tot[z]){
					int bj=0;
					break;
				}
			}
			if(bj==0){
				break;
			}
			for(int z=i;z<=j;z++){
				int e[26],ws;
				memset(e,0,sizeof(0));
				if(z==i){
					ws=b[i][0];
					for(int q=1;q<=b[i][0];q++){
						e[q]=b[i][q];
					}
				}else{
					ws=max(b[z][0],ws);
					for(int q=1;q<=ws;q++){
						if(e[q]==b[z][q]){
							e[q]=0;
						}else{
							e[q]=1;
						}
					}
				}if(z==j){
				int ff=1;
				for(int q=1;q<=max(ws,d[0]);q++){
					if(e[q]!=d[q]){
						ff=0;
					}
				}
					if(ff==1){
						ans++;
						tot[++s]=j;
					}	
				}		
			}			
		}
	}
	cout<<ans;
	return 0;
}
