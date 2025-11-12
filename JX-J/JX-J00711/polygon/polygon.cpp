#include<bits/stdc++.h>
using namespace std;
int a[100010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	long long ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	if(n==3){
		if(a[1]+a[2]+a[3]>2*max(a[1],max(a[2],a[3]))){
			cout<<1<<endl;
			return 0;
		}
		else{
			cout<<0<<endl;
			return 0;
		}
	}
	if(n==4){
		if(a[1]+a[2]+a[3]>2*max(a[1],max(a[2],a[3])))
		ans++;
		if(a[1]+a[2]+a[4]>2*max(a[1],max(a[2],a[4])))
		ans++;
		if(a[1]+a[4]+a[3]>2*max(a[1],max(a[4],a[3])))
		ans++;
		if(a[4]+a[2]+a[3]>2*max(a[4],max(a[2],a[3])))
		ans++;
		if(a[1]+a[2]+a[3]+a[4]>2*max(a[1],max(a[2],max(a[3],a[4]))))
		ans++;
		cout<<ans<<endl;
		return 0;
	}
	else if(n==5){
	for(int i=1;i<=n;i++)
	for(int j=i+1;j<=n;j++)
	for(int k=j+1;k<=n;k++)
	if(a[i]+a[k]+a[j]>2*max(a[i],max(a[j],a[k])))
	ans++;
	for(int i=1;i<=n;i++)
	for(int j=i+1;j<=n;j++)
	for(int k=j+1;k<=n;k++)
	for(int m=k+1;m<=n;m++)
	if(a[i]+a[k]+a[j]+a[m]>2*max(a[i],max(a[j],max(a[k],a[m]))))
	ans++;
		for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		for(int k=j+1;k<=n;k++)
		for(int m=k+1;m<=n;m++)
		for(int l=m+1;l<=n;l++)
		if(a[i]+a[k]+a[j]+a[m]+a[l]>2*max(a[i],max(a[j],max(a[k],max(a[l],a[m])))))
		ans++;
		cout<<ans<<endl;
		return 0;
	}
	else if(n==6){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					if(a[i]+a[k]+a[j]>2*max(a[i],max(a[j],a[k]))){
						ans++;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int m=k+1;m<=n;m++){
						if(a[i]+a[k]+a[j]+a[m]>2*max(a[i],max(a[j],max(a[k],a[m])))){
							ans++;
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int m=k+1;m<=n;m++){
						for(int l=m+1;l<=n;l++)
						if(a[i]+a[k]+a[j]+a[m]+a[l]>2*max(a[i],max(a[j],max(a[k],max(a[l],a[m]))))){
							ans++;
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		for(int k=j+1;k<=n;k++)
		for(int m=k+1;m<=n;m++)
		for(int l=m+1;l<=n;l++)
		for(int o=l+1;o<=n;o++)
		if(a[i]+a[k]+a[j]+a[m]+a[l]+a[o]>2*max(a[i],max(a[j],max(a[k],max(a[l],max(a[m],a[o]))))))
		ans++;
		cout<<ans<<endl;
		return 0;
	}
	else if(n==7){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					if(a[i]+a[k]+a[j]>2*max(a[i],max(a[j],a[k]))){
						ans++;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int m=k+1;m<=n;m++){
						if(a[i]+a[k]+a[j]+a[m]>2*max(a[i],max(a[j],max(a[k],a[m])))){
							ans++;
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int m=k+1;m<=n;m++){
						for(int l=m+1;l<=n;l++)
						if(a[i]+a[k]+a[j]+a[m]+a[l]>2*max(a[i],max(a[j],max(a[k],max(a[l],a[m]))))){
							ans++;
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		for(int k=j+1;k<=n;k++)
		for(int m=k+1;m<=n;m++)
		for(int l=m+1;l<=n;l++)
		for(int o=l+1;o<=n;o++)
		if(a[i]+a[k]+a[j]+a[m]+a[l]+a[o]>2*max(a[i],max(a[j],max(a[k],max(a[l],max(a[m],a[o]))))))
		ans++;
		for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		for(int k=j+1;k<=n;k++)
		for(int m=k+1;m<=n;m++)
		for(int l=m+1;l<=n;l++)
		for(int o=l+1;o<=n;o++)
		for(int u=o+1;u<=n;u++)
		if(a[i]+a[k]+a[j]+a[m]+a[l]+a[o]+a[u]>2*max(a[i],max(a[j],max(a[k],max(a[l],max(a[m],max(a[o],a[u])))))))
		ans++;
		cout<<ans<<endl;
		return 0;
	}
	else if(n==8){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					if(a[i]+a[k]+a[j]>2*max(a[i],max(a[j],a[k]))){
						ans++;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int m=k+1;m<=n;m++){
						if(a[i]+a[k]+a[j]+a[m]>2*max(a[i],max(a[j],max(a[k],a[m])))){
							ans++;
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int m=k+1;m<=n;m++){
						for(int l=m+1;l<=n;l++)
						if(a[i]+a[k]+a[j]+a[m]+a[l]>2*max(a[i],max(a[j],max(a[k],max(a[l],a[m]))))){
							ans++;
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		for(int k=j+1;k<=n;k++)
		for(int m=k+1;m<=n;m++)
		for(int l=m+1;l<=n;l++)
		for(int o=l+1;o<=n;o++)
		if(a[i]+a[k]+a[j]+a[m]+a[l]+a[o]>2*max(a[i],max(a[j],max(a[k],max(a[l],max(a[m],a[o]))))))
		ans++;
		for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		for(int k=j+1;k<=n;k++)
		for(int m=k+1;m<=n;m++)
		for(int l=m+1;l<=n;l++)
		for(int o=l+1;o<=n;o++)
		for(int u=o+1;u<=n;u++)
		if(a[i]+a[k]+a[j]+a[m]+a[l]+a[o]+a[u]>2*max(a[i],max(a[j],max(a[k],max(a[l],max(a[m],max(a[o],a[u])))))))
		ans++;
		for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		for(int k=j+1;k<=n;k++)
		for(int m=k+1;m<=n;m++)
		for(int l=m+1;l<=n;l++)
		for(int o=l+1;o<=n;o++)
		for(int u=o+1;u<=n;u++)
		for(int p=o+1;p<=n;p++)
		if(a[i]+a[k]+a[j]+a[m]+a[l]+a[o]+a[u]+a[p]>2*max(a[i],max(a[j],max(a[k],max(a[l],max(a[m],max(a[o],max(a[u],a[p]))))))))
		ans++;
		cout<<ans<<endl;
		return 0;
	}
	else if(n==9){
		for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		for(int k=j+1;k<=n;k++)
		if(a[i]+a[k]+a[j]>2*max(a[i],max(a[j],a[k])))
		ans++;
		for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		for(int k=j+1;k<=n;k++)
		for(int m=k+1;m<=n;m++)
		if(a[i]+a[k]+a[j]+a[m]>2*max(a[i],max(a[j],max(a[k],a[m]))))
		ans++;
		for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		for(int k=j+1;k<=n;k++)
		for(int m=k+1;m<=n;m++)
		for(int l=m+1;l<=n;l++)
		if(a[i]+a[k]+a[j]+a[m]+a[l]>2*max(a[i],max(a[j],max(a[k],max(a[l],a[m])))))
		ans++;
		for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		for(int k=j+1;k<=n;k++)
		for(int m=k+1;m<=n;m++)
		for(int l=m+1;l<=n;l++)
		for(int o=l+1;o<=n;o++)
		if(a[i]+a[k]+a[j]+a[m]+a[l]+a[o]>2*max(a[i],max(a[j],max(a[k],max(a[l],max(a[m],a[o]))))))
		ans++;
		for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		for(int k=j+1;k<=n;k++)
		for(int m=k+1;m<=n;m++)
		for(int l=m+1;l<=n;l++)
		for(int o=l+1;o<=n;o++)
		for(int u=o+1;u<=n;u++)
		if(a[i]+a[k]+a[j]+a[m]+a[l]+a[o]+a[u]>2*max(a[i],max(a[j],max(a[k],max(a[l],max(a[m],max(a[o],a[u])))))))
		ans++;
		for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		for(int k=j+1;k<=n;k++)
		for(int m=k+1;m<=n;m++)
		for(int l=m+1;l<=n;l++)
		for(int o=l+1;o<=n;o++)
		for(int u=o+1;u<=n;u++)
		for(int p=o+1;p<=n;p++)
		if(a[i]+a[k]+a[j]+a[m]+a[l]+a[o]+a[u]+a[p]>2*max(a[i],max(a[j],max(a[k],max(a[l],max(a[m],max(a[o],max(a[u],a[p]))))))))
		ans++;
		for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		for(int k=j+1;k<=n;k++)
		for(int m=k+1;m<=n;m++)
		for(int l=m+1;l<=n;l++)
		for(int o=l+1;o<=n;o++)
		for(int u=o+1;u<=n;u++)
		for(int p=o+1;p<=n;p++)
		for(int y=p+1;y<=n;y++)
		if(a[i]+a[k]+a[j]+a[m]+a[l]+a[o]+a[u]+a[p]+a[y]>2*max(a[i],max(a[j],max(a[k],max(a[l],max(a[m],max(a[o],max(a[u],max(a[p],a[y])))))))))
		ans++;
		cout<<ans<<endl;
		return 0;
	}
	else if(n==10){
		for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		for(int k=j+1;k<=n;k++)
		if(a[i]+a[k]+a[j]>2*max(a[i],max(a[j],a[k])))
		ans++;
		for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		for(int k=j+1;k<=n;k++)
		for(int m=k+1;m<=n;m++)
		if(a[i]+a[k]+a[j]+a[m]>2*max(a[i],max(a[j],max(a[k],a[m]))))
		ans++;
		for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		for(int k=j+1;k<=n;k++)
		for(int m=k+1;m<=n;m++)
		for(int l=m+1;l<=n;l++)
		if(a[i]+a[k]+a[j]+a[m]+a[l]>2*max(a[i],max(a[j],max(a[k],max(a[l],a[m])))))
		ans++;
		for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		for(int k=j+1;k<=n;k++)
		for(int m=k+1;m<=n;m++)
		for(int l=m+1;l<=n;l++)
		for(int o=l+1;o<=n;o++)
		if(a[i]+a[k]+a[j]+a[m]+a[l]+a[o]>2*max(a[i],max(a[j],max(a[k],max(a[l],max(a[m],a[o]))))))
		ans++;
		for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		for(int k=j+1;k<=n;k++)
		for(int m=k+1;m<=n;m++)
		for(int l=m+1;l<=n;l++)
		for(int o=l+1;o<=n;o++)
		for(int u=o+1;u<=n;u++)
		if(a[i]+a[k]+a[j]+a[m]+a[l]+a[o]+a[u]>2*max(a[i],max(a[j],max(a[k],max(a[l],max(a[m],max(a[o],a[u])))))))
		ans++;
		for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		for(int k=j+1;k<=n;k++)
		for(int m=k+1;m<=n;m++)
		for(int l=m+1;l<=n;l++)
		for(int o=l+1;o<=n;o++)
		for(int u=o+1;u<=n;u++)
		for(int p=o+1;p<=n;p++)
		if(a[i]+a[k]+a[j]+a[m]+a[l]+a[o]+a[u]+a[p]>2*max(a[i],max(a[j],max(a[k],max(a[l],max(a[m],max(a[o],max(a[u],a[p]))))))))
		ans++;
		for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		for(int k=j+1;k<=n;k++)
		for(int m=k+1;m<=n;m++)
		for(int l=m+1;l<=n;l++)
		for(int o=l+1;o<=n;o++)
		for(int u=o+1;u<=n;u++)
		for(int p=o+1;p<=n;p++)
		for(int y=p+1;y<=n;y++)
		if(a[i]+a[k]+a[j]+a[m]+a[l]+a[o]+a[u]+a[p]+a[y]>2*max(a[i],max(a[j],max(a[k],max(a[l],max(a[m],max(a[o],max(a[u],max(a[p],a[y])))))))))
		ans++;
		if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]+a[10]>2*max(a[1],max(a[2],max(a[3],max(a[4],max(a[5],max(a[6],max(a[7],max(a[8],max(a[9],a[10]))))))))))
		ans++;
		cout<<ans<<endl;
		return 0;
	}
	else if(n==11){
		for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		for(int k=j+1;k<=n;k++)
		if(a[i]+a[k]+a[j]>2*max(a[i],max(a[j],a[k])))
		ans++;
		for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		for(int k=j+1;k<=n;k++)
		for(int m=k+1;m<=n;m++)
		if(a[i]+a[k]+a[j]+a[m]>2*max(a[i],max(a[j],max(a[k],a[m]))))
		ans++;
		for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		for(int k=j+1;k<=n;k++)
		for(int m=k+1;m<=n;m++)
		for(int l=m+1;l<=n;l++)
		if(a[i]+a[k]+a[j]+a[m]+a[l]>2*max(a[i],max(a[j],max(a[k],max(a[l],a[m])))))
		ans++;
		for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		for(int k=j+1;k<=n;k++)
		for(int m=k+1;m<=n;m++)
		for(int l=m+1;l<=n;l++)
		for(int o=l+1;o<=n;o++)
		if(a[i]+a[k]+a[j]+a[m]+a[l]+a[o]>2*max(a[i],max(a[j],max(a[k],max(a[l],max(a[m],a[o]))))))
		ans++;
		for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		for(int k=j+1;k<=n;k++)
		for(int m=k+1;m<=n;m++)
		for(int l=m+1;l<=n;l++)
		for(int o=l+1;o<=n;o++)
		for(int u=o+1;u<=n;u++)
		if(a[i]+a[k]+a[j]+a[m]+a[l]+a[o]+a[u]>2*max(a[i],max(a[j],max(a[k],max(a[l],max(a[m],max(a[o],a[u])))))))
		ans++;
		for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		for(int k=j+1;k<=n;k++)
		for(int m=k+1;m<=n;m++)
		for(int l=m+1;l<=n;l++)
		for(int o=l+1;o<=n;o++)
		for(int u=o+1;u<=n;u++)
		for(int p=o+1;p<=n;p++)
		if(a[i]+a[k]+a[j]+a[m]+a[l]+a[o]+a[u]+a[p]>2*max(a[i],max(a[j],max(a[k],max(a[l],max(a[m],max(a[o],max(a[u],a[p]))))))))
		ans++;
		for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		for(int k=j+1;k<=n;k++)
		for(int m=k+1;m<=n;m++)
		for(int l=m+1;l<=n;l++)
		for(int o=l+1;o<=n;o++)
		for(int u=o+1;u<=n;u++)
		for(int p=o+1;p<=n;p++)
		for(int y=p+1;y<=n;y++)
		if(a[i]+a[k]+a[j]+a[m]+a[l]+a[o]+a[u]+a[p]+a[y]>2*max(a[i],max(a[j],max(a[k],max(a[l],max(a[m],max(a[o],max(a[u],max(a[p],a[y])))))))))
		ans++;
		for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		for(int k=j+1;k<=n;k++)
		for(int m=k+1;m<=n;m++)
		for(int l=m+1;l<=n;l++)
		for(int o=l+1;o<=n;o++)
		for(int u=o+1;u<=n;u++)
		for(int p=o+1;p<=n;p++)
		for(int y=p+1;y<=n;y++)
		for(int h=y+1;h<=n;h++)
		if(a[i]+a[k]+a[j]+a[m]+a[l]+a[o]+a[u]+a[p]+a[y]+a[h]>2*max(a[i],max(a[j],max(a[k],max(a[l],max(a[m],max(a[o],max(a[u],max(a[p],max(a[y],a[h]))))))))))
		ans++;
		for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		for(int k=j+1;k<=n;k++)
		for(int m=k+1;m<=n;m++)
		for(int l=m+1;l<=n;l++)
		for(int o=l+1;o<=n;o++)
		for(int u=o+1;u<=n;u++)
		for(int p=o+1;p<=n;p++)
		for(int y=p+1;y<=n;y++)
		for(int h=y+1;h<=n;h++)
		for(int b=h+1;b<=n;b++)
		if(a[i]+a[k]+a[j]+a[m]+a[l]+a[o]+a[u]+a[p]+a[y]+a[h]+a[b]>2*max(a[i],max(a[j],max(a[k],max(a[l],max(a[m],max(a[o],max(a[u],max(a[p],max(a[y],max(a[h],a[b])))))))))))
		ans++;
		cout<<ans<<endl;
		return 0;
	}
	return 0;
}
