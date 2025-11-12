#include<bits/stdc++.h>
using namespace std;
int n,a[10005],ans=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3){
		if(a[1]+a[2]+a[3]>2*max(max(a[1],a[2]),a[3]))
			cout<<1;
		else
			cout<<0;
	}
	if(n==4){
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					if(a[i]+a[j]+a[k]>2*max(max(a[i],a[j]),a[k]))
						ans++;
		if(a[1]+a[2]+a[3]+a[4]>2*max(max(max(a[1],a[2]),a[3]),a[4]))
			cout<<ans+1;
		else
			cout<<ans;
		return 0;
	}
	if(n==5){
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					if(a[i]+a[j]+a[k]>2*max(max(a[i],a[j]),a[k]))
						ans++;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					for(int l=k+1;l<=n;l++)
						if(a[i]+a[j]+a[k]+a[l]>2*max(max(max(a[i],a[j]),a[k]),a[l]))
							ans++;
		if(a[1]+a[2]+a[3]+a[4]+a[5]>2*max(max(max(max(a[1],a[2]),a[3]),a[4]),a[5]))
			cout<<ans+1;
		else
			cout<<ans;
		return 0;
	}
	if(n==6){
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					if(a[i]+a[j]+a[k]>2*max(max(a[i],a[j]),a[k]))
						ans++;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					for(int l=k+1;l<=n;l++)
						if(a[i]+a[j]+a[k]+a[l]>2*max(max(max(a[i],a[j]),a[k]),a[l]))
							ans++;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					for(int l=k+1;l<=n;l++)
						for(int o=l+1;o<=n;o++)
							if(a[i]+a[j]+a[k]+a[l]+a[o]>2*max(max(max(max(a[i],a[j]),a[k]),a[l]),a[o]))
								ans++;
		if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]>2*max(max(max(max(max(a[1],a[2]),a[3]),a[4]),a[5]),a[6]))
			cout<<ans+1;
		else
			cout<<ans;
		return 0;
	}
	if(n==7){
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					if(a[i]+a[j]+a[k]>2*max(max(a[i],a[j]),a[k]))
						ans++;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					for(int l=k+1;l<=n;l++)
						if(a[i]+a[j]+a[k]+a[l]>2*max(max(max(a[i],a[j]),a[k]),a[l]))
							ans++;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					for(int l=k+1;l<=n;l++)
						for(int o=l+1;o<=n;o++)
							if(a[i]+a[j]+a[k]+a[l]+a[o]>2*max(max(max(max(a[i],a[j]),a[k]),a[l]),a[o]))
								ans++;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					for(int l=k+1;l<=n;l++)
						for(int o=l+1;o<=n;o++)
							for(int p=o+1;p<=n;p++)
								if(a[i]+a[j]+a[k]+a[l]+a[o]+a[p]>2*max(max(max(max(max(a[i],a[j]),a[k]),a[l]),a[o]),a[p]))
									ans++;
		if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]>2*max(max(max(max(max(max(a[1],a[2]),a[3]),a[4]),a[5]),a[6]),a[7]))
			cout<<ans+1;
		else
			cout<<ans;
		return 0;
	}
	if(n==8){
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					if(a[i]+a[j]+a[k]>2*max(max(a[i],a[j]),a[k]))
						ans++;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					for(int l=k+1;l<=n;l++)
						if(a[i]+a[j]+a[k]+a[l]>2*max(max(max(a[i],a[j]),a[k]),a[l]))
							ans++;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					for(int l=k+1;l<=n;l++)
						for(int o=l+1;o<=n;o++)
							if(a[i]+a[j]+a[k]+a[l]+a[o]>2*max(max(max(max(a[i],a[j]),a[k]),a[l]),a[o]))
								ans++;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					for(int l=k+1;l<=n;l++)
						for(int o=l+1;o<=n;o++)
							for(int p=o+1;p<=n;p++)
								if(a[i]+a[j]+a[k]+a[l]+a[o]+a[p]>2*max(max(max(max(max(a[i],a[j]),a[k]),a[l]),a[o]),a[p]))
									ans++;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					for(int l=k+1;l<=n;l++)
						for(int o=l+1;o<=n;o++)
							for(int p=o+1;p<=n;p++)
								for(int r=p+1;r<=n;r++)
									if(a[i]+a[j]+a[k]+a[l]+a[o]+a[p]+a[r]>2*max(max(max(max(max(max(a[i],a[j]),a[k]),a[l]),a[o]),a[p]),a[r]))
										ans++;
		if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]>2*max(max(max(max(max(max(max(a[1],a[2]),a[3]),a[4]),a[5]),a[6]),a[7]),a[8]))
			cout<<ans+1;
		else
			cout<<ans;
		return 0;
	}
	if(n==9){
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					if(a[i]+a[j]+a[k]>2*max(max(a[i],a[j]),a[k]))
						ans++;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					for(int l=k+1;l<=n;l++)
						if(a[i]+a[j]+a[k]+a[l]>2*max(max(max(a[i],a[j]),a[k]),a[l]))
							ans++;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					for(int l=k+1;l<=n;l++)
						for(int o=l+1;o<=n;o++)
							if(a[i]+a[j]+a[k]+a[l]+a[o]>2*max(max(max(max(a[i],a[j]),a[k]),a[l]),a[o]))
								ans++;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					for(int l=k+1;l<=n;l++)
						for(int o=l+1;o<=n;o++)
							for(int p=o+1;p<=n;p++)
								if(a[i]+a[j]+a[k]+a[l]+a[o]+a[p]>2*max(max(max(max(max(a[i],a[j]),a[k]),a[l]),a[o]),a[p]))
									ans++;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					for(int l=k+1;l<=n;l++)
						for(int o=l+1;o<=n;o++)
							for(int p=o+1;p<=n;p++)
								for(int r=p+1;r<=p;r++)
									if(a[i]+a[j]+a[k]+a[l]+a[o]+a[p]+a[r]>2*max(max(max(max(max(max(a[i],a[j]),a[k]),a[l]),a[o]),a[p]),a[r]))
									ans++;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					for(int l=k+1;l<=n;l++)
						for(int o=l+1;o<=n;o++)
							for(int p=o+1;p<=n;p++)
								for(int r=p+1;r<=n;r++)
									for(int s=r+1;s<=n;s++)
										if(a[i]+a[j]+a[k]+a[l]+a[o]+a[p]+a[r]+a[s]>2*max(max(max(max(max(max(max(a[i],a[j]),a[k]),a[l]),a[o]),a[p]),a[r]),a[s]))
											ans++;
		if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]>2*max(max(max(max(max(max(max(max(a[1],a[2]),a[3]),a[4]),a[5]),a[6]),a[7]),a[8]),a[9]))
			cout<<ans+1;
		else
			cout<<ans;
		return 0;
	}
	if(n==10){
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					if(a[i]+a[j]+a[k]>2*max(max(a[i],a[j]),a[k]))
						ans++;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					for(int l=k+1;l<=n;l++)
						if(a[i]+a[j]+a[k]+a[l]>2*max(max(max(a[i],a[j]),a[k]),a[l]))
							ans++;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					for(int l=k+1;l<=n;l++)
						for(int o=l+1;o<=n;o++)
							if(a[i]+a[j]+a[k]+a[l]+a[o]>2*max(max(max(max(a[i],a[j]),a[k]),a[l]),a[o]))
								ans++;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					for(int l=k+1;l<=n;l++)
						for(int o=l+1;o<=n;o++)
							for(int p=o+1;p<=n;p++)
								if(a[i]+a[j]+a[k]+a[l]+a[o]+a[p]>2*max(max(max(max(max(a[i],a[j]),a[k]),a[l]),a[o]),a[p]))
									ans++;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					for(int l=k+1;l<=n;l++)
						for(int o=l+1;o<=n;o++)
							for(int p=o+1;p<=n;p++)
								for(int r=p+1;r<=p;r++)
									if(a[i]+a[j]+a[k]+a[l]+a[o]+a[p]+a[r]>2*max(max(max(max(max(max(a[i],a[j]),a[k]),a[l]),a[o]),a[p]),a[r]))
									ans++;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					for(int l=k+1;l<=n;l++)
						for(int o=l+1;o<=n;o++)
							for(int p=o+1;p<=n;p++)
								for(int r=p+1;r<=n;r++)
									for(int s=r+1;s<=n;s++)
										if(a[i]+a[j]+a[k]+a[l]+a[o]+a[p]+a[r]+a[s]>2*max(max(max(max(max(max(max(a[i],a[j]),a[k]),a[l]),a[o]),a[p]),a[r]),a[s]))
											ans++;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
					for(int l=k+1;l<=n;l++)
						for(int o=l+1;o<=n;o++)
							for(int p=o+1;p<=n;p++)
								for(int r=p+1;r<=n;r++)
									for(int s=r+1;s<=n;s++)
										for(int t=s+1;t<=n;t++)
											if(a[i]+a[j]+a[k]+a[l]+a[o]+a[p]+a[r]+a[s]+a[t]>2*max(max(max(max(max(max(max(max(a[i],a[j]),a[k]),a[l]),a[o]),a[p]),a[r]),a[s]),a[t]))
												ans++;
		if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]+a[10]>2*max(max(max(max(max(max(max(max(max(a[1],a[2]),a[3]),a[4]),a[5]),a[6]),a[7]),a[8]),a[9]),a[10]))
			cout<<ans+1;
		else
			cout<<ans;
		return 0;
	}
	return 0;
}
