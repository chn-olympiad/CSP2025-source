#include<bits/stdc++.h>
using namespace std;
const long long mo=998244353;
int n,a[5012],sum[5012];
long long ans=0;
bool flag=1;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);

		if(a[i]!=1) flag=0;
	}
	if(flag){    //全为1 
	long long t;
		for(int i=3;i<=n;i++){
			t=1;
			for(int j=0;j<=i-1;j++){
				t=(t*(n-j))/(1+j)%mo;
			}
			ans=(ans+t)%mo;
		}
	cout<<ans;
	return 0;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	if(n==3){
		if(sum[2]>a[3]) ans++;
	}
	else if(n==4){
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			for(int k=j+1;k<=n;k++)
				if(a[j]+a[i]>a[k]) ans++;
	if(sum[3]>a[4]) ans++;					
	}
	else if(n==5){
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			for(int k=j+1;k<=n;k++)
				if(a[j]+a[i]>a[k]) ans++;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			for(int k=j+1;k<=n;k++)
				for(int l=k+1;l<=n;l++)
				if(a[j]+a[i]+a[k]>a[l]) ans++;	
	if(sum[4]>a[5]) ans++;			
	}
	else if(n==6){
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			for(int k=j+1;k<=n;k++)
				if(a[j]+a[i]>a[k]) ans++;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			for(int k=j+1;k<=n;k++)
				for(int l=k+1;l<=n;l++)
				if(a[j]+a[i]+a[k]>a[l]) ans++;	
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			for(int k=j+1;k<=n;k++)
				for(int l=k+1;l<=n;l++)
					for(int r=l+1;r<=n;r++) if(a[j]+a[i]+a[k]+a[l]>a[r]) ans++;	
	if(sum[5]>a[6]) ans++;	
	}
	else if(n==7){
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			for(int k=j+1;k<=n;k++)
				if(a[j]+a[i]>a[k]) ans++;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			for(int k=j+1;k<=n;k++)
				for(int l=k+1;l<=n;l++)
				if(a[j]+a[i]+a[k]>a[l]) ans++;	
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			for(int k=j+1;k<=n;k++)
				for(int l=k+1;l<=n;l++)
					for(int r=l+1;r<=n;r++) if(a[j]+a[i]+a[k]+a[l]>a[r]) ans++;	
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			for(int k=j+1;k<=n;k++)
				for(int l=k+1;l<=n;l++)
					for(int r=l+1;r<=n;r++)
						for(int s=r+1;s<=n;s++) if(a[j]+a[i]+a[k]+a[l]+a[r]>a[s]) ans++;		
	if(sum[6]>a[7]) ans++;	
	}
	else if(n==8){
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			for(int k=j+1;k<=n;k++)
				if(a[j]+a[i]>a[k]) ans++;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			for(int k=j+1;k<=n;k++)
				for(int l=k+1;l<=n;l++)
				if(a[j]+a[i]+a[k]>a[l]) ans++;	
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			for(int k=j+1;k<=n;k++)
				for(int l=k+1;l<=n;l++)
					for(int r=l+1;r<=n;r++) if(a[j]+a[i]+a[k]+a[l]>a[r]) ans++;	
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			for(int k=j+1;k<=n;k++)
				for(int l=k+1;l<=n;l++)
					for(int r=l+1;r<=n;r++)
						for(int s=r+1;s<=n;s++) if(a[j]+a[i]+a[k]+a[l]+a[r]>a[s]) ans++;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			for(int k=j+1;k<=n;k++)
				for(int l=k+1;l<=n;l++)
					for(int r=l+1;r<=n;r++)
						for(int s=r+1;s<=n;s++) 
							for(int v=s+1;v<=n;v++)if(a[j]+a[i]+a[k]+a[l]+a[r]+a[s]>a[v]) ans++;			
	if(sum[7]>a[8]) ans++;		
	}
	else if(n==9){
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			for(int k=j+1;k<=n;k++)
				if(a[j]+a[i]>a[k]) ans++;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			for(int k=j+1;k<=n;k++)
				for(int l=k+1;l<=n;l++)
				if(a[j]+a[i]+a[k]>a[l]) ans++;	
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			for(int k=j+1;k<=n;k++)
				for(int l=k+1;l<=n;l++)
					for(int r=l+1;r<=n;r++) if(a[j]+a[i]+a[k]+a[l]>a[r]) ans++;	
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			for(int k=j+1;k<=n;k++)
				for(int l=k+1;l<=n;l++)
					for(int r=l+1;r<=n;r++)
						for(int s=r+1;s<=n;s++) if(a[j]+a[i]+a[k]+a[l]+a[r]>a[s]) ans++;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			for(int k=j+1;k<=n;k++)
				for(int l=k+1;l<=n;l++)
					for(int r=l+1;r<=n;r++)
						for(int s=r+1;s<=n;s++) 
							for(int v=s+1;v<=n;v++)if(a[j]+a[i]+a[k]+a[l]+a[r]+a[s]>a[v]) ans++;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			for(int k=j+1;k<=n;k++)
				for(int l=k+1;l<=n;l++)
					for(int r=l+1;r<=n;r++)
						for(int s=r+1;s<=n;s++) 
							for(int v=s+1;v<=n;v++)
							for(int x=v+1;x<=n;x++)if(a[j]+a[i]+a[k]+a[l]+a[r]+a[s]+a[v]>a[x]) ans++;				
	if(sum[8]>a[9]) ans++;				
	}
	else {
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			for(int k=j+1;k<=n;k++)
				if(a[j]+a[i]>a[k]) ans++;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			for(int k=j+1;k<=n;k++)
				for(int l=k+1;l<=n;l++)
				if(a[j]+a[i]+a[k]>a[l]) ans++;	
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			for(int k=j+1;k<=n;k++)
				for(int l=k+1;l<=n;l++)
					for(int r=l+1;r<=n;r++) if(a[j]+a[i]+a[k]+a[l]>a[r]) ans++;	
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			for(int k=j+1;k<=n;k++)
				for(int l=k+1;l<=n;l++)
					for(int r=l+1;r<=n;r++)
						for(int s=r+1;s<=n;s++) if(a[j]+a[i]+a[k]+a[l]+a[r]>a[s]) ans++;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			for(int k=j+1;k<=n;k++)
				for(int l=k+1;l<=n;l++)
					for(int r=l+1;r<=n;r++)
						for(int s=r+1;s<=n;s++) 
							for(int v=s+1;v<=n;v++)if(a[j]+a[i]+a[k]+a[l]+a[r]+a[s]>a[v]) ans++;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			for(int k=j+1;k<=n;k++)
				for(int l=k+1;l<=n;l++)
					for(int r=l+1;r<=n;r++)
						for(int s=r+1;s<=n;s++) 
							for(int v=s+1;v<=n;v++)
							for(int x=v+1;x<=n;x++)if(a[j]+a[i]+a[k]+a[l]+a[r]+a[s]+a[v]>a[x]) ans++;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			for(int k=j+1;k<=n;k++)
				for(int l=k+1;l<=n;l++)
					for(int r=l+1;r<=n;r++)
						for(int s=r+1;s<=n;s++) 
							for(int v=s+1;v<=n;v++)
								for(int x=v+1;x<=n;x++)
								for(int y=x+1;y<=n;y++)if(a[j]+a[i]+a[k]+a[l]+a[r]+a[s]+a[v]+a[x]>a[y]) ans++;					
	if(sum[9]>a[10]) ans++;		
	}
	cout<<ans%mo;
	return 0;
}