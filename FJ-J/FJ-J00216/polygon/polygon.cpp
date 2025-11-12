#include<bits/stdc++.h>

using namespace std;

const int mod=998244353;

int n;
int a[5005];

bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int flag=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) flag=0;
	}
	if(n<=3){
		if(n<3){
			cout<<0;
			return 0;
		}else if(n==3){
			if(a[1]+a[2]+a[3]>max(a[1],max(a[2],a[3]))*2) cout<<1;
			else cout<<0;
			return 0;
		}
	}else if(n<=10){
		sort(a+1,a+1+n,cmp);
		int ans=0;
		if(n==4){
			for(int i=1;i<=n;i++)
				for(int j=i+1;j<=n;j++)
					for(int k=j+1;k<=n;k++)
							if(a[i]+a[j]+a[k]>2*max(a[i],max(a[j],a[k]))) ans++;
			if(a[1]+a[2]+a[3]+a[4]>2*max(a[1],max(a[2],max(a[3],a[4])))) ans++;
			cout<<ans%mod;
			return 0;
		}else if(n==5){
			for(int i=1;i<=n;i++)
				for(int j=i+1;j<=n;j++)
					for(int k=j+1;k<=n;k++)
							if(a[i]+a[j]+a[k]>2*max(a[i],max(a[j],a[k]))) ans++;
			for(int i=1;i<=n;i++)
				for(int j=i+1;j<=n;j++)
					for(int k=j+1;k<=n;k++)
						for(int l=k+1;l<=n;l++)
							if(a[i]+a[j]+a[k]+a[l]>2*max(a[i],max(a[j],max(a[k],a[l])))) ans++;
			if(a[1]+a[2]+a[3]+a[4]+a[5]>2*max(a[1],max(a[2],max(a[3],max(a[4],a[5]))))) ans++;
			cout<<ans%mod;
			return 0;
		}else if(n==6){
			for(int i=1;i<=n;i++)
				for(int j=i+1;j<=n;j++)
					for(int k=j+1;k<=n;k++)
							if(a[i]+a[j]+a[k]>2*max(a[i],max(a[j],a[k])))
								ans++;
			for(int i=1;i<=n;i++)
				for(int j=i+1;j<=n;j++)
					for(int k=j+1;k<=n;k++)
						for(int l=k+1;l<=n;l++)
							if(a[i]+a[j]+a[k]+a[l]>2*max(a[i],max(a[j],max(a[k],a[l])))) ans++;
			for(int i=1;i<=n;i++)
				for(int j=i+1;j<=n;j++)
					for(int k=j+1;k<=n;k++)
						for(int l=k+1;l<=n;l++)
							if(a[i]+a[j]+a[k]+a[l]>2*max(a[i],max(a[j],max(a[k],a[l])))) ans++;
			for(int i=1;i<=n;i++)
				for(int j=i+1;j<=n;j++)
					for(int k=j+1;k<=n;k++)
						for(int l=k+1;l<=n;l++)
							for(int p=l+1;p<=n;p++)
								if(a[i]+a[j]+a[k]+a[l]+a[p]>2*max(a[i],max(a[j],max(a[k],max(a[l],a[p]))))) ans++;
			if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]>2*max(a[1],max(a[2],max(a[3],max(a[4],max(a[5],a[6])))))) ans++;
			cout<<ans%mod;
			return 0;
		}else if(n==7){
			for(int i=1;i<=n;i++)
				for(int j=i+1;j<=n;j++)
					for(int k=j+1;k<=n;k++){
							if(a[i]+a[j]+a[k]>2*max(a[i],max(a[j],a[k])))
								ans++;
					}
			for(int i=1;i<=n;i++)
				for(int j=i+1;j<=n;j++)
					for(int k=j+1;k<=n;k++)
						for(int l=k+1;l<=n;l++)
							if(a[i]+a[j]+a[k]+a[l]>2*max(a[i],max(a[j],max(a[k],a[l])))) ans++;
			for(int i=1;i<=n;i++)
				for(int j=i+1;j<=n;j++)
					for(int k=j+1;k<=n;k++)
						for(int l=k+1;l<=n;l++)
							if(a[i]+a[j]+a[k]+a[l]>2*max(a[i],max(a[j],max(a[k],a[l])))) ans++;
			for(int i=1;i<=n;i++)
				for(int j=i+1;j<=n;j++)
					for(int k=j+1;k<=n;k++)
						for(int l=k+1;l<=n;l++)
							for(int p=l+1;p<=n;p++)
								if(a[i]+a[j]+a[k]+a[l]+a[p]>2*max(a[i],max(a[j],max(a[k],max(a[l],a[p]))))) ans++;
			for(int i=1;i<=n;i++)
				for(int j=i+1;j<=n;j++)
					for(int k=j+1;k<=n;k++)
						for(int l=k+1;l<=n;l++)
							for(int p=l+1;p<=n;p++)
								for(int o=p+1;o<=n;o++)
									if(a[i]+a[j]+a[k]+a[l]+a[p]+a[o]>2*max(a[i],max(a[j],max(a[k],max(a[l],max(a[p],a[o])))))) ans++;
			if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]>2*max(a[1],max(a[2],max(a[3],max(a[4],max(a[5],max(a[6],a[7]))))))) ans++;
			cout<<ans%mod;
			return 0;
		}else if(n==8){
			for(int i=1;i<=n;i++)
				for(int j=i+1;j<=n;j++)
					for(int k=j+1;k<=n;k++){
							if(a[i]+a[j]+a[k]>2*max(a[i],max(a[j],a[k])))
								ans++;
					}
			for(int i=1;i<=n;i++)
				for(int j=i+1;j<=n;j++)
					for(int k=j+1;k<=n;k++)
						for(int l=k+1;l<=n;l++)
							if(a[i]+a[j]+a[k]+a[l]>2*max(a[i],max(a[j],max(a[k],a[l])))) ans++;
			for(int i=1;i<=n;i++)
				for(int j=i+1;j<=n;j++)
					for(int k=j+1;k<=n;k++)
						for(int l=k+1;l<=n;l++)
							if(a[i]+a[j]+a[k]+a[l]>2*max(a[i],max(a[j],max(a[k],a[l])))) ans++;
			for(int i=1;i<=n;i++)
				for(int j=i+1;j<=n;j++)
					for(int k=j+1;k<=n;k++)
						for(int l=k+1;l<=n;l++)
							for(int p=l+1;p<=n;p++)
								if(a[i]+a[j]+a[k]+a[l]+a[p]>2*max(a[i],max(a[j],max(a[k],max(a[l],a[p]))))) ans++;
			for(int i=1;i<=n;i++)
				for(int j=i+1;j<=n;j++)
					for(int k=j+1;k<=n;k++)
						for(int l=k+1;l<=n;l++)
							for(int p=l+1;p<=n;p++)
								for(int o=p+1;o<=n;o++)
									if(a[i]+a[j]+a[k]+a[l]+a[p]+a[o]>2*max(a[i],max(a[j],max(a[k],max(a[l],max(a[p],a[o])))))) ans++;
			for(int i=1;i<=n;i++)
				for(int j=i+1;j<=n;j++)
					for(int k=j+1;k<=n;k++)
						for(int l=k+1;l<=n;l++)
							for(int p=l+1;p<=n;p++)
								for(int o=p+1;o<=n;o++)
									for(int u=o+1;u<=n;u++)
										if(a[i]+a[j]+a[k]+a[l]+a[p]+a[o]+a[u]>2*max(a[i],max(a[j],max(a[k],max(a[l],max(a[p],max(a[o],a[u]))))))) ans++;
			if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]>2*max(a[1],max(a[2],max(a[3],max(a[4],max(a[5],max(a[6],max(a[7],a[8])))))))) ans++;
			cout<<ans%mod;
			return 0;
		}else if(n==9){
			for(int i=1;i<=n;i++)
				for(int j=i+1;j<=n;j++)
					for(int k=j+1;k<=n;k++){
							if(a[i]+a[j]+a[k]>2*max(a[i],max(a[j],a[k])))
								ans++;
					}
			for(int i=1;i<=n;i++)
				for(int j=i+1;j<=n;j++)
					for(int k=j+1;k<=n;k++)
						for(int l=k+1;l<=n;l++)
							if(a[i]+a[j]+a[k]+a[l]>2*max(a[i],max(a[j],max(a[k],a[l])))) ans++;
			for(int i=1;i<=n;i++)
				for(int j=i+1;j<=n;j++)
					for(int k=j+1;k<=n;k++)
						for(int l=k+1;l<=n;l++)
							if(a[i]+a[j]+a[k]+a[l]>2*max(a[i],max(a[j],max(a[k],a[l])))) ans++;
			for(int i=1;i<=n;i++)
				for(int j=i+1;j<=n;j++)
					for(int k=j+1;k<=n;k++)
						for(int l=k+1;l<=n;l++)
							for(int p=l+1;p<=n;p++)
								if(a[i]+a[j]+a[k]+a[l]+a[p]>2*max(a[i],max(a[j],max(a[k],max(a[l],a[p]))))) ans++;
			for(int i=1;i<=n;i++)
				for(int j=i+1;j<=n;j++)
					for(int k=j+1;k<=n;k++)
						for(int l=k+1;l<=n;l++)
							for(int p=l+1;p<=n;p++)
								for(int o=p+1;o<=n;o++)
									if(a[i]+a[j]+a[k]+a[l]+a[p]+a[o]>2*max(a[i],max(a[j],max(a[k],max(a[l],max(a[p],a[o])))))) ans++;
			for(int i=1;i<=n;i++)
				for(int j=i+1;j<=n;j++)
					for(int k=j+1;k<=n;k++)
						for(int l=k+1;l<=n;l++)
							for(int p=l+1;p<=n;p++)
								for(int o=p+1;o<=n;o++)
									for(int u=o+1;u<=n;u++)
										for(int t=u+1;t<=n;t++)
											if(a[i]+a[j]+a[k]+a[l]+a[p]+a[o]+a[u]+a[t]>2*max(a[i],max(a[j],max(a[k],max(a[l],max(a[p],max(a[o],max(a[u],a[t])))))))) ans++;
			
			if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]>2*max(a[1],max(a[2],max(a[3],max(a[4],max(a[5],max(a[6],max(a[7],max(a[8],a[9]))))))))) ans++;
			cout<<ans%mod;
			return 0;
		}else if(n==10){
			for(int i=1;i<=n;i++)
				for(int j=i+1;j<=n;j++)
					for(int k=j+1;k<=n;k++){
							if(a[i]+a[j]+a[k]>2*max(a[i],max(a[j],a[k])))
								ans++;
					}
			for(int i=1;i<=n;i++)
				for(int j=i+1;j<=n;j++)
					for(int k=j+1;k<=n;k++)
						for(int l=k+1;l<=n;l++)
							if(a[i]+a[j]+a[k]+a[l]>2*max(a[i],max(a[j],max(a[k],a[l])))) ans++;
			for(int i=1;i<=n;i++)
				for(int j=i+1;j<=n;j++)
					for(int k=j+1;k<=n;k++)
						for(int l=k+1;l<=n;l++)
							if(a[i]+a[j]+a[k]+a[l]>2*max(a[i],max(a[j],max(a[k],a[l])))) ans++;
			for(int i=1;i<=n;i++)
				for(int j=i+1;j<=n;j++)
					for(int k=j+1;k<=n;k++)
						for(int l=k+1;l<=n;l++)
							for(int p=l+1;p<=n;p++)
								if(a[i]+a[j]+a[k]+a[l]+a[p]>2*max(a[i],max(a[j],max(a[k],max(a[l],a[p]))))) ans++;
			for(int i=1;i<=n;i++)
				for(int j=i+1;j<=n;j++)
					for(int k=j+1;k<=n;k++)
						for(int l=k+1;l<=n;l++)
							for(int p=l+1;p<=n;p++)
								for(int o=p+1;o<=n;o++)
									if(a[i]+a[j]+a[k]+a[l]+a[p]+a[o]>2*max(a[i],max(a[j],max(a[k],max(a[l],max(a[p],a[o])))))) ans++;
			for(int i=1;i<=n;i++)
				for(int j=i+1;j<=n;j++)
					for(int k=j+1;k<=n;k++)
						for(int l=k+1;l<=n;l++)
							for(int p=l+1;p<=n;p++)
								for(int o=p+1;o<=n;o++)
									for(int u=o+1;u<=n;u++)
										for(int t=u+1;t<=n;t++)
											for(int r=t+1;r<=n;r++)
											if(a[i]+a[j]+a[k]+a[l]+a[p]+a[o]+a[u]+a[t]+a[r]>2*max(a[i],max(a[j],max(a[k],max(a[l],max(a[p],max(a[o],max(a[u],max(a[t],a[r]))))))))) ans++;
			
			if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]+a[10]>2*max(a[1],max(a[2],max(a[3],max(a[4],max(a[5],max(a[6],max(a[7],max(a[8],max(a[9],a[10])))))))))) ans++;
			cout<<ans%mod;
			return 0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
