#include<bits/stdc++.h>
using namespace std;
long long a[5005];
long long jie(int x){
	long long f=1;
	for(int i=1;i<=x;i++)
		f*=x;
	return f;
}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n<3){
		cout<<0;
	}
	else if(n==3){
		if(max(a[1],max(a[2],a[3]))*2<a[1]+a[2]+a[3])
			cout<<1;
		else
			cout<<0;
	}
	else if(n==4){
		long long ans=0;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					if(max(a[i],max(a[j],a[k]))*2<a[i]+a[j]+a[k])
						ans++;
		ans%=998244353;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					for(int l=k+1;l<=n;l++)
						if(max(max(a[i],a[l]),max(a[j],a[k]))*2<a[i]+a[j]+a[k]+a[l])
							ans++;
		ans%=998244353;
		cout<<ans;
	}
	else if(n==5){
		long long ans=0;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					if(max(a[i],max(a[j],a[k]))*2<a[i]+a[j]+a[k])
						ans++;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					for(int l=k+1;l<=n;l++)
						if(max(max(a[i],a[l]),max(a[j],a[k]))*2<a[i]+a[j]+a[k]+a[l])
							ans++;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					for(int l=k+1;l<=n;l++)
						for(int x=l+1;x<=n;x++)
							if(max(max(a[x],max(a[i],a[l])),max(a[j],a[k]))*2<a[i]+a[j]+a[k]+a[l]+a[x])
								ans++;
		cout<<ans;
	}
	else if(n==6){
		long long ans=0;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					if(max(a[i],max(a[j],a[k]))*2<a[i]+a[j]+a[k])
						ans++;
		ans%=998244353;				
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					for(int l=k+1;l<=n;l++)
						if(max(max(a[i],a[l]),max(a[j],a[k]))*2<a[i]+a[j]+a[k]+a[l])
							ans++;
		ans%=998244353;					
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					for(int l=k+1;l<=n;l++)
						for(int x=l+1;x<=n;x++)
							if(max(max(a[x],max(a[i],a[l])),max(a[j],a[k]))*2<a[i]+a[j]+a[k]+a[l]+a[x])
								ans++;
		ans%=998244353;							
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					for(int l=k+1;l<=n;l++)
						for(int x=l+1;x<=n;x++)
							for(int y=x+1;y<=n;y++) 
								if(max(max(max(a[y],a[x]),max(a[i],a[l])),max(a[j],a[k]))*2<a[i]+a[j]+a[k]+a[l]+a[x]+a[y])
									ans++;
		cout<<ans%998244353;
	}
	else if(n==7){
		long long ans=0;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					if(max(a[i],max(a[j],a[k]))*2<a[i]+a[j]+a[k])
						ans++;
		ans%=998244353;					
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					for(int l=k+1;l<=n;l++)
						if(max(max(a[i],a[l]),max(a[j],a[k]))*2<a[i]+a[j]+a[k]+a[l])
							ans++;
		ans%=998244353;						
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					for(int l=k+1;l<=n;l++)
						for(int x=l+1;x<=n;x++)
							if(max(max(a[x],max(a[i],a[l])),max(a[j],a[k]))*2<a[i]+a[j]+a[k]+a[l]+a[x])
								ans++;
		ans%=998244353;							
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					for(int l=k+1;l<=n;l++)
						for(int x=l+1;x<=n;x++)
							for(int y=x+1;y<=n;y++) 
								if(max(max(max(a[y],a[x]),max(a[i],a[l])),max(a[j],a[k]))*2<a[i]+a[j]+a[k]+a[l]+a[x]+a[y])
									ans++;
		ans%=998244353;								
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					for(int l=k+1;l<=n;l++)
						for(int x=l+1;x<=n;x++)
							for(int y=x+1;y<=n;y++) 
								for(int z=y+1;z<=n;z++)
									if(max(max(max(a[y],a[x]),max(a[i],a[l])),max(a[j],max(a[k],a[z])))*2<a[i]+a[j]+a[k]+a[l]+a[x]+a[y]+a[z])
										ans++;
		ans%=998244353;									
		cout<<ans;
	}
	else if(n==8){
		long long ans=0;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					if(max(a[i],max(a[j],a[k]))*2<a[i]+a[j]+a[k])
						ans++;
		ans%=998244353;					
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					for(int l=k+1;l<=n;l++)
						if(max(max(a[i],a[l]),max(a[j],a[k]))*2<a[i]+a[j]+a[k]+a[l])
							ans++;
		ans%=998244353;						
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					for(int l=k+1;l<=n;l++)
						for(int x=l+1;x<=n;x++)
							if(max(max(a[x],max(a[i],a[l])),max(a[j],a[k]))*2<a[i]+a[j]+a[k]+a[l]+a[x])
								ans++;
		ans%=998244353;							
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					for(int l=k+1;l<=n;l++)
						for(int x=l+1;x<=n;x++)
							for(int y=x+1;y<=n;y++) 
								if(max(max(max(a[y],a[x]),max(a[i],a[l])),max(a[j],a[k]))*2<a[i]+a[j]+a[k]+a[l]+a[x]+a[y])
									ans++;
		ans%=998244353;								
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					for(int l=k+1;l<=n;l++)
						for(int x=l+1;x<=n;x++)
							for(int y=x+1;y<=n;y++) 
								for(int z=y+1;z<=n;z++)
									if(max(max(max(a[y],a[x]),max(a[i],a[l])),max(a[j],max(a[k],a[z])))*2<a[i]+a[j]+a[k]+a[l]+a[x]+a[y]+a[z])
										ans++;
		ans%=998244353;									
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					for(int l=k+1;l<=n;l++)
						for(int x=l+1;x<=n;x++)
							for(int y=x+1;y<=n;y++) 
								for(int z=y+1;z<=n;z++)
									for(int u=z+1;u<=n;u++)
										if(max(max(max(a[y],a[x]),max(a[i],a[l])),max(max(a[j],a[u]),max(a[k],a[z])))*2<a[i]+a[j]+a[k]+a[l]+a[x]+a[y]+a[z]+a[u])
										ans++;
		ans%=998244353;									
		cout<<ans;
	}
	else if(n==9){
		long long ans=0;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					if(max(a[i],max(a[j],a[k]))*2<a[i]+a[j]+a[k])
						ans++;
		ans%=998244353;					
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					for(int l=k+1;l<=n;l++)
						if(max(max(a[i],a[l]),max(a[j],a[k]))*2<a[i]+a[j]+a[k]+a[l])
							ans++;
		ans%=998244353;						
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					for(int l=k+1;l<=n;l++)
						for(int x=l+1;x<=n;x++)
							if(max(max(a[x],max(a[i],a[l])),max(a[j],a[k]))*2<a[i]+a[j]+a[k]+a[l]+a[x])
								ans++;
		ans%=998244353;							
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					for(int l=k+1;l<=n;l++)
						for(int x=l+1;x<=n;x++)
							for(int y=x+1;y<=n;y++) 
								if(max(max(max(a[y],a[x]),max(a[i],a[l])),max(a[j],a[k]))*2<a[i]+a[j]+a[k]+a[l]+a[x]+a[y])
									ans++;
		ans%=998244353;								
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					for(int l=k+1;l<=n;l++)
						for(int x=l+1;x<=n;x++)
							for(int y=x+1;y<=n;y++) 
								for(int z=y+1;z<=n;z++)
									if(max(max(max(a[y],a[x]),max(a[i],a[l])),max(a[j],max(a[k],a[z])))*2<a[i]+a[j]+a[k]+a[l]+a[x]+a[y]+a[z])
										ans++;
		ans%=998244353;									
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					for(int l=k+1;l<=n;l++)
						for(int x=l+1;x<=n;x++)
							for(int y=x+1;y<=n;y++) 
								for(int z=y+1;z<=n;z++)
									for(int u=z+1;u<=n;u++)
										if(max(max(max(a[y],a[x]),max(a[i],a[l])),max(max(a[j],a[u]),max(a[k],a[z])))*2<a[i]+a[j]+a[k]+a[l]+a[x]+a[y]+a[z]+a[u])
										ans++;
		ans%=998244353;									
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					for(int l=k+1;l<=n;l++)
						for(int x=l+1;x<=n;x++)
							for(int y=x+1;y<=n;y++) 
								for(int z=y+1;z<=n;z++)
									for(int u=z+1;u<=n;u++)
										for(int t=u+1;t<=n;t++)
											if(max(max(max(a[y],a[x]),max(a[i],a[l])),max(max(a[j],a[u]),max(a[k],max(a[z],a[t]))))*2<a[i]+a[j]+a[k]+a[l]+a[x]+a[y]+a[z]+a[u]+a[t])
												ans++;
		ans%=998244353;											
		cout<<ans;
	}
	else if(n==10){
		long long ans=0;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					if(max(a[i],max(a[j],a[k]))*2<a[i]+a[j]+a[k])
						ans++;
		ans%=998244353;					
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					for(int l=k+1;l<=n;l++)
						if(max(max(a[i],a[l]),max(a[j],a[k]))*2<a[i]+a[j]+a[k]+a[l])
							ans++;
		ans%=998244353;						
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					for(int l=k+1;l<=n;l++)
						for(int x=l+1;x<=n;x++)
							if(max(max(a[x],max(a[i],a[l])),max(a[j],a[k]))*2<a[i]+a[j]+a[k]+a[l]+a[x])
								ans++;
		ans%=998244353;							
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					for(int l=k+1;l<=n;l++)
						for(int x=l+1;x<=n;x++)
							for(int y=x+1;y<=n;y++) 
								if(max(max(max(a[y],a[x]),max(a[i],a[l])),max(a[j],a[k]))*2<a[i]+a[j]+a[k]+a[l]+a[x]+a[y])
									ans++;
		ans%=998244353;								
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					for(int l=k+1;l<=n;l++)
						for(int x=l+1;x<=n;x++)
							for(int y=x+1;y<=n;y++) 
								for(int z=y+1;z<=n;z++)
									if(max(max(max(a[y],a[x]),max(a[i],a[l])),max(a[j],max(a[k],a[z])))*2<a[i]+a[j]+a[k]+a[l]+a[x]+a[y]+a[z])
										ans++;
		ans%=998244353;									
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					for(int l=k+1;l<=n;l++)
						for(int x=l+1;x<=n;x++)
							for(int y=x+1;y<=n;y++) 
								for(int z=y+1;z<=n;z++)
									for(int u=z+1;u<=n;u++)
										if(max(max(max(a[y],a[x]),max(a[i],a[l])),max(max(a[j],a[u]),max(a[k],a[z])))*2<a[i]+a[j]+a[k]+a[l]+a[x]+a[y]+a[z]+a[u])
										ans++;
		ans%=998244353;									
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					for(int l=k+1;l<=n;l++)
						for(int x=l+1;x<=n;x++)
							for(int y=x+1;y<=n;y++) 
								for(int z=y+1;z<=n;z++)
									for(int u=z+1;u<=n;u++)
										for(int t=u+1;t<=n;t++)
											if(max(max(max(a[y],a[x]),max(a[i],a[l])),max(max(a[j],a[u]),max(a[k],max(a[z],a[t]))))*2<a[i]+a[j]+a[k]+a[l]+a[x]+a[y]+a[z]+a[u]+a[t])
												ans++;
		ans%=998244353;											
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					for(int l=k+1;l<=n;l++)
						for(int x=l+1;x<=n;x++)
							for(int y=x+1;y<=n;y++) 
								for(int z=y+1;z<=n;z++)
									for(int u=z+1;u<=n;u++)
										for(int t=u+1;t<=n;t++)
											for(int o=t+1;o<=n;o++)
												if(max(max(max(a[y],max(a[x],a[o])),max(a[i],a[l])),max(max(a[j],a[u]),max(a[k],max(a[z],a[t]))))*2<a[i]+a[j]+a[k]+a[l]+a[x]+a[y]+a[z]+a[u]+a[t]+a[o])
													ans++;
		ans%=998244353;										
		cout<<ans;
	}
	else{
		long long ans=0,sum=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1)
			sum++;
		}
		for(int i=4;i<=n;i++){
			ans+=jie(sum)/(i*jie(sum-i));
		}
		cout<<ans;
	}
	return 0;
}
