#include<bits/stdc++.h>
using namespace std;
long long n,mod=998244353;
long long a[5005],num,ans;
long long maxx,l,k,x;
struct pol{
	int sum;
	int maxn;
	int en;
};
pol m[5005][10005];
bool cmp(int x,int y){
	return x>y;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(a[i],maxx);
	}
	if(maxx==1){
		int s=0;
		for(int i=2;i<=n;i++){
			int k=i;
			while(k<n){
				s+=n-k;
				k++;
			}
		}
		cout<<s;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	if(n==3){
		for(int i=1;i<=n;i++){
			num+=a[i];
		}
		if(num>a[1]*2) ans++;
		cout<<ans;
		return 0;
	}
	if(n==4){
		if(a[1]+a[2]+a[3]>a[1]*2) ans++;
		if(a[1]+a[2]+a[4]>a[1]*2) ans++;
		if(a[2]+a[3]+a[4]>a[2]*2) ans++;
		if(a[1]+a[2]+a[3]+a[4]>a[1]*2) ans++;
		cout<<ans;
		return 0;
	}
	if(n==5){
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int l=j+1;l<=n;l++)
					if(a[i]+a[j]+a[l]>a[i]*2) ans++;
		if(a[1]+a[2]+a[3]+a[4]>a[1]*2) ans++;
		if(a[1]+a[2]+a[3]+a[5]>a[1]*2) ans++;
		if(a[1]+a[2]+a[4]+a[5]>a[1]*2) ans++;
		if(a[1]+a[3]+a[4]+a[5]>a[1]*2) ans++;
		if(a[2]+a[3]+a[4]+a[5]>a[2]*2) ans++;
		for(int i=1;i<=n;i++) num+=a[i];
		if(num>a[1]*2) ans++;
		cout<<ans;
		return 0;
	}
	if(n==6){
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int l=j+1;l<=n;l++)
					if(a[i]+a[j]+a[l]>a[i]*2) ans++;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int l=j+1;l<=n;l++)
					for(int f=l+1;f<=n;f++)
						if(a[i]+a[j]+a[l]+a[f]>a[i]*2) ans++;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int l=j+1;l<=n;l++)
					for(int f=l+1;f<=n;f++)
						for(int h=f+1;h<=n;h++)
							if(a[i]+a[j]+a[l]+a[f]+a[h]>a[i]*2) ans++;
		for(int i=1;i<=n;i++) num+=a[i];
		if(num>a[1]*2) ans++;
		cout<<ans;
		return 0;
	}
	if(n==7){
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int l=j+1;l<=n;l++)
					if(a[i]+a[j]+a[l]>a[i]*2) ans++;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int l=j+1;l<=n;l++)
					for(int f=l+1;f<=n;f++)
						if(a[i]+a[j]+a[l]+a[f]>a[i]*2) ans++;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int l=j+1;l<=n;l++)
					for(int f=l+1;f<=n;f++)
						for(int h=f+1;h<=n;h++)
							if(a[i]+a[j]+a[l]+a[f]+a[h]>a[i]*2) ans++;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int l=j+1;l<=n;l++)
					for(int f=l+1;f<=n;f++)
						for(int h=f+1;h<=n;h++)
							for(int k=h+1;k<=n;k++)
								if(a[i]+a[j]+a[l]+a[f]+a[h]+a[k]>a[i]*2) ans++;
		for(int i=1;i<=n;i++) num+=a[i];
		if(num>a[1]*2) ans++;
		cout<<ans;
		return 0;
	}
	if(n==8){
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int l=j+1;l<=n;l++)
					if(a[i]+a[j]+a[l]>a[i]*2) ans++;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int l=j+1;l<=n;l++)
					for(int f=l+1;f<=n;f++)
						if(a[i]+a[j]+a[l]+a[f]>a[i]*2) ans++;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int l=j+1;l<=n;l++)
					for(int f=l+1;f<=n;f++)
						for(int h=f+1;h<=n;h++)
							if(a[i]+a[j]+a[l]+a[f]+a[h]>a[i]*2) ans++;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int l=j+1;l<=n;l++)
					for(int f=l+1;f<=n;f++)
						for(int h=f+1;h<=n;h++)
							for(int k=h+1;k<=n;k++)
								if(a[i]+a[j]+a[l]+a[f]+a[h]+a[k]>a[i]*2) ans++;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int l=j+1;l<=n;l++)
					for(int f=l+1;f<=n;f++)
						for(int h=f+1;h<=n;h++)
							for(int k=h+1;k<=n;k++)
								for(int t=k+1;t<=n;t++) 
									if(a[i]+a[j]+a[l]+a[f]+a[h]+a[k]+a[t]>a[i]*2) ans++;
		for(int i=1;i<=n;i++) num+=a[i];
		if(num>a[1]*2) ans++;
		cout<<ans;
		return 0;
	}
	if(n==9){
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int l=j+1;l<=n;l++)
					if(a[i]+a[j]+a[l]>a[i]*2) ans++;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int l=j+1;l<=n;l++)
					for(int f=l+1;f<=n;f++)
						if(a[i]+a[j]+a[l]+a[f]>a[i]*2) ans++;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int l=j+1;l<=n;l++)
					for(int f=l+1;f<=n;f++)
						for(int h=f+1;h<=n;h++)
							if(a[i]+a[j]+a[l]+a[f]+a[h]>a[i]*2) ans++;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int l=j+1;l<=n;l++)
					for(int f=l+1;f<=n;f++)
						for(int h=f+1;h<=n;h++)
							for(int k=h+1;k<=n;k++)
								if(a[i]+a[j]+a[l]+a[f]+a[h]+a[k]>a[i]*2) ans++;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int l=j+1;l<=n;l++)
					for(int f=l+1;f<=n;f++)
						for(int h=f+1;h<=n;h++)
							for(int k=h+1;k<=n;k++)
								for(int t=k+1;t<=n;t++) 
									if(a[i]+a[j]+a[l]+a[f]+a[h]+a[k]+a[t]>a[i]*2) ans++;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int l=j+1;l<=n;l++)
					for(int f=l+1;f<=n;f++)
						for(int h=f+1;h<=n;h++)
							for(int k=h+1;k<=n;k++)
								for(int t=k+1;t<=n;t++) 
									for(int u=t+1;u<=n;u++)
										if(a[i]+a[j]+a[l]+a[f]+a[h]+a[k]+a[t]+a[u]>a[i]*2) ans++;
		for(int i=1;i<=n;i++) num+=a[i];
		if(num>a[1]*2) ans++;
		cout<<ans;
		return 0;
	}
	if(n==10){
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int l=j+1;l<=n;l++)
					if(a[i]+a[j]+a[l]>a[i]*2) ans++;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int l=j+1;l<=n;l++)
					for(int f=l+1;f<=n;f++)
						if(a[i]+a[j]+a[l]+a[f]>a[i]*2) ans++;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int l=j+1;l<=n;l++)
					for(int f=l+1;f<=n;f++)
						for(int h=f+1;h<=n;h++)
							if(a[i]+a[j]+a[l]+a[f]+a[h]>a[i]*2) ans++;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int l=j+1;l<=n;l++)
					for(int f=l+1;f<=n;f++)
						for(int h=f+1;h<=n;h++)
							for(int k=h+1;k<=n;k++)
								if(a[i]+a[j]+a[l]+a[f]+a[h]+a[k]>a[i]*2) ans++;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int l=j+1;l<=n;l++)
					for(int f=l+1;f<=n;f++)
						for(int h=f+1;h<=n;h++)
							for(int k=h+1;k<=n;k++)
								for(int t=k+1;t<=n;t++) 
									if(a[i]+a[j]+a[l]+a[f]+a[h]+a[k]+a[t]>a[i]*2) ans++;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int l=j+1;l<=n;l++)
					for(int f=l+1;f<=n;f++)
						for(int h=f+1;h<=n;h++)
							for(int k=h+1;k<=n;k++)
								for(int t=k+1;t<=n;t++) 
									for(int u=t+1;u<=n;u++)
										if(a[i]+a[j]+a[l]+a[f]+a[h]+a[k]+a[t]+a[u]>a[i]*2) ans++;
		if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]>a[1]*2) ans++;
		if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[10]>a[1]*2) ans++;
		if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[9]+a[10]>a[1]*2) ans++;
		if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[8]+a[9]+a[10]>a[1]*2) ans++;
		if(a[1]+a[2]+a[3]+a[4]+a[5]+a[7]+a[8]+a[9]+a[10]>a[1]*2) ans++;
		if(a[1]+a[2]+a[3]+a[4]+a[6]+a[7]+a[8]+a[9]+a[10]>a[1]*2) ans++;
		if(a[1]+a[2]+a[3]+a[5]+a[6]+a[7]+a[8]+a[9]+a[10]>a[1]*2) ans++;
		if(a[1]+a[2]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]+a[10]>a[1]*2) ans++;
		if(a[1]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]+a[10]>a[1]*2) ans++;
		if(a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]+a[10]>a[2]*2) ans++;
		for(int i=1;i<=n;i++) num+=a[i];
		if(num>a[1]*2) ans++;
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			m[2][++l].sum=a[i]+a[j];
			m[2][l].en=j;
			m[2][l].maxn=a[i];
		}
	}
	x=l;
	l=0; k=1;
	for(int i=3;i<=n;i++){
		for(int j=m[i-1][k].en+1;j<=n;j++){
			m[i][++l].sum=m[i-1][k].sum+a[j];
			m[i][l].en=j;
			m[i][l].maxn=m[i-1][k].maxn;
			if(m[i][l].sum>m[i][l].maxn*2) ans++;
			ans%=mod; 
			if(j==n && k<x){
				k++;
				j=m[i-1][k].en+1;
			}
		}
	}
	cout<<ans;
	return 0;
}
