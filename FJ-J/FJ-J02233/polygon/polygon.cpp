#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5;
int n,a[N],b[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    int ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)b[i]=a[i]+b[i-1];
	if(b[n]>2*a[n])ans++;
	if(n==3)cout<<ans;
	if(n==4){
		for(int i=1;i<n;i++)if(b[n]-a[i]>2*a[n])ans++;
		if(b[n-1]>2*a[n-1])ans++;
		cout<<ans;
	}if(n==5){
		for(int i=1;i<=n-2;i++)
			for(int j=i+1;j<=n-1;j++)
				for(int k=j+1;k<=n;k++)
					if(a[i]+a[j]>a[k])ans++;
		for(int i=1;i<n;i++)if(b[n]-a[i]>2*a[n])ans++;
		if(b[n-1]>2*a[n-1])ans++;
		cout<<ans;
	}if(n==6){
		for(int i=1;i<=n-2;i++)
			for(int j=i+1;j<=n-1;j++)
				for(int k=j+1;k<=n;k++)
					if(a[i]+a[j]>a[k])ans++;
		for(int i=1;i<=n-3;i++)
			for(int j=i+1;j<=n-2;j++)
				for(int k=j+1;k<=n-1;k++)
					for(int q=k+1;q<=n;q++)
						if(a[i]+a[j]+a[k]>a[q])ans++;
		for(int i=1;i<n;i++)if(b[n]-a[i]>2*a[n])ans++;
		if(b[n-1]>2*a[n-1])ans++;
		cout<<ans;
	}if(n==7){
		for(int i=1;i<=n-2;i++)
			for(int j=i+1;j<=n-1;j++)
				for(int k=j+1;k<=n;k++)
					if(a[i]+a[j]>a[k])ans++;
		for(int i=1;i<=n-3;i++)
			for(int j=i+1;j<=n-2;j++)
				for(int k=j+1;k<=n-1;k++)
					for(int q=k+1;q<=n;q++)
						if(a[i]+a[j]+a[k]>a[q])ans++;
		for(int i=1;i<=n-4;i++)
			for(int j=i+1;j<=n-3;j++)
				for(int k=j+1;k<=n-2;k++)
					for(int q=k+1;q<=n-1;q++)
						for(int p=q+1;p<=n;p++)
							if(a[i]+a[j]+a[k]+a[q]>a[p])ans++;
		for(int i=1;i<n;i++)if(b[n]-a[i]>2*a[n])ans++;
		if(b[n-1]>2*a[n-1])ans++;
		cout<<ans;
	}if(n==8){
		for(int i=1;i<=n-2;i++)
			for(int j=i+1;j<=n-1;j++)
				for(int k=j+1;k<=n;k++)
					if(a[i]+a[j]>a[k])ans++;
		for(int i=1;i<=n-3;i++)
			for(int j=i+1;j<=n-2;j++)
				for(int k=j+1;k<=n-1;k++)
					for(int q=k+1;q<=n;q++)
						if(a[i]+a[j]+a[k]>a[q])ans++;
		for(int i=1;i<=n-4;i++)
			for(int j=i+1;j<=n-3;j++)
				for(int k=j+1;k<=n-2;k++)
					for(int q=k+1;q<=n-1;q++)
						for(int p=q+1;p<=n;p++)
							if(a[i]+a[j]+a[k]+a[q]>a[p])ans++;
		for(int i=1;i<=n-5;i++)
			for(int j=i+1;j<=n-4;j++)
				for(int k=j+1;k<=n-3;k++)
					for(int q=k+1;q<=n-2;q++)
						for(int p=q+1;p<=n-1;p++)
							for(int c=p+1;c<=n;c++)
								if(a[i]+a[j]+a[k]+a[q]+a[p]>a[c])ans++;
		for(int i=1;i<n;i++)if(b[n]-a[i]>2*a[n])ans++;
		if(b[n-1]>2*a[n-1])ans++;
		cout<<ans;
	}if(n==9){
		for(int i=1;i<=n-2;i++)
			for(int j=i+1;j<=n-1;j++)
				for(int k=j+1;k<=n;k++)
					if(a[i]+a[j]>a[k])ans++;
		for(int i=1;i<=n-3;i++)
			for(int j=i+1;j<=n-2;j++)
				for(int k=j+1;k<=n-1;k++)
					for(int q=k+1;q<=n;q++)
						if(a[i]+a[j]+a[k]>a[q])ans++;
		for(int i=1;i<=n-4;i++)
			for(int j=i+1;j<=n-3;j++)
				for(int k=j+1;k<=n-2;k++)
					for(int q=k+1;q<=n-1;q++)
						for(int p=q+1;p<=n;p++)
							if(a[i]+a[j]+a[k]+a[q]>a[p])ans++;
		for(int i=1;i<=n-5;i++)
			for(int j=i+1;j<=n-4;j++)
				for(int k=j+1;k<=n-3;k++)
					for(int q=k+1;q<=n-2;q++)
						for(int p=q+1;p<=n-1;p++)
							for(int c=p+1;c<=n;c++)
								if(a[i]+a[j]+a[k]+a[q]+a[p]>a[c])ans++;
		for(int i=1;i<=n-6;i++)
			for(int j=i+1;j<=n-5;j++)
				for(int k=j+1;k<=n-4;k++)
					for(int q=k+1;q<=n-3;q++)
						for(int p=q+1;p<=n-2;p++)
							for(int c=p+1;c<=n-1;c++)
								for(int d=c+1;d<=n;d++)
									if(a[i]+a[j]+a[k]+a[q]+a[p]+a[c]>a[d])ans++;
		for(int i=1;i<n;i++)if(b[n]-a[i]>2*a[n])ans++;
		if(b[n-1]>2*a[n-1])ans++;
		cout<<ans;
	}if(n==10){
		for(int i=1;i<=n-2;i++)
			for(int j=i+1;j<=n-1;j++)
				for(int k=j+1;k<=n;k++)
					if(a[i]+a[j]>a[k])ans++;
		for(int i=1;i<=n-3;i++)
			for(int j=i+1;j<=n-2;j++)
				for(int k=j+1;k<=n-1;k++)
					for(int q=k+1;q<=n;q++)
						if(a[i]+a[j]+a[k]>a[q])ans++;
		for(int i=1;i<=n-4;i++)
			for(int j=i+1;j<=n-3;j++)
				for(int k=j+1;k<=n-2;k++)
					for(int q=k+1;q<=n-1;q++)
						for(int p=q+1;p<=n;p++)
							if(a[i]+a[j]+a[k]+a[q]>a[p])ans++;
		for(int i=1;i<=n-5;i++)
			for(int j=i+1;j<=n-4;j++)
				for(int k=j+1;k<=n-3;k++)
					for(int q=k+1;q<=n-2;q++)
						for(int p=q+1;p<=n-1;p++)
							for(int c=p+1;c<=n;c++)
								if(a[i]+a[j]+a[k]+a[q]+a[p]>a[c])ans++;
		for(int i=1;i<=n-6;i++)
			for(int j=i+1;j<=n-5;j++)
				for(int k=j+1;k<=n-4;k++)
					for(int q=k+1;q<=n-3;q++)
						for(int p=q+1;p<=n-2;p++)
							for(int c=p+1;c<=n-1;c++)
								for(int d=c+1;d<=n;d++)
									if(a[i]+a[j]+a[k]+a[q]+a[p]+a[c]>a[d])ans++;
		for(int i=1;i<=n-7;i++)
			for(int j=i+1;j<=n-6;j++)
				for(int k=j+1;k<=n-5;k++)
					for(int q=k+1;q<=n-4;q++)
						for(int p=q+1;p<=n-3;p++)
							for(int c=p+1;c<=n-2;c++)
								for(int d=c+1;d<=n-1;d++)
									for(int e=d+1;e<=n;e++)
										if(a[i]+a[j]+a[k]+a[q]+a[p]+a[c]+a[d]>a[e])ans++;
		for(int i=1;i<n;i++)if(b[n]-a[i]>2*a[n])ans++;
		if(b[n-1]>2*a[n-1])ans++;
		cout<<ans;
	}
	return 0;
}
