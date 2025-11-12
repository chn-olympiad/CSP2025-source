#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],sum,maxx=-1,cnt;
void f(long long side){
	sum=0;
	maxx=-1;
	if(side==3)
		for(int i=1;i<=n-2;i++)
			for(int j=i+1;j<=n-1;j++)
				for(int k=j+1;k<=n;k++){
					sum=a[i]+a[j]+a[k];
					maxx=max(a[i],max(a[j],a[k]));
					if(sum>2*maxx){
						cnt++;
					} 
				}
	if(side==4)
		for(int i=1;i<=n-3;i++)
			for(int j=i+1;j<=n-2;j++)
				for(int k=j+1;k<=n-1;k++)
					for(int l=k+1;l<=n;l++){
						sum=a[i]+a[j]+a[k]+a[l];
						maxx=max(a[i],max(a[j],max(a[k],a[l])));
						if(sum>2*maxx){
							cnt++;
						} 
					}
	if(side==5)
		for(int i=1;i<=n-4;i++)
			for(int j=i+1;j<=n-3;j++)
				for(int k=j+1;k<=n-2;k++)
					for(int l=k+1;l<=n-1;l++)
						for(int m=l+1;m<=n;m++){
							sum=a[i]+a[j]+a[k]+a[l]+a[m];
							maxx=max(a[i],max(a[j],max(a[k],max(a[l],a[m]))));
							if(sum>2*maxx){
								cnt++;
							}
						}
	if(side==6)
		for(int i=1;i<=n-5;i++)
			for(int j=i+1;j<=n-4;j++)
				for(int k=j+1;k<=n-3;k++)
					for(int l=k+1;l<=n-2;l++)
						for(int m=l+1;m<=n-1;m++)
							for(int o=m+1;o<=n;o++){
								sum=a[i]+a[j]+a[k]+a[l]+a[m]+a[o];
								maxx=max(a[i],max(a[j],max(a[k],max(a[l],max(a[m],a[o])))));
								if(sum>2*maxx){
									cnt++;
								}
							}
	if(side==7)
		for(int i=1;i<=n-6;i++)
			for(int j=i+1;j<=n-5;j++)
				for(int k=j+1;k<=n-4;k++)
					for(int l=k+1;l<=n-3;l++)
						for(int m=l+1;m<=n-2;m++)
							for(int o=m+1;o<=n-1;o++)
								for(int p=o+1;p<=n;p++){
									sum=a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p];
									maxx=max(a[i],max(a[j],max(a[k],max(a[l],max(a[m],max(a[o],a[p]))))));
									if(sum>2*maxx){
										cnt++;
									}
								}
	if(side==8)
	for(int i=1;i<=n-7;i++)
		for(int j=i+1;j<=n-6;j++)
			for(int k=j+1;k<=n-5;k++)
				for(int l=k+1;l<=n-4;l++)
					for(int m=l+1;m<=n-3;m++)
						for(int o=m+1;o<=n-2;o++)
							for(int p=o+1;p<=n-1;p++)
								for(int q=p+1;q<=n;q++){
									sum=a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q];
									maxx=max(a[i],max(a[j],max(a[k],max(a[l],max(a[m],max(a[o],max(a[p],a[q])))))));
									if(sum>2*maxx){
										cnt++;
									}
								}
	if(side==9)
		for(int i=1;i<=n-8;i++)
			for(int j=i+1;j<=n-7;j++)
				for(int k=j+1;k<=n-6;k++)
					for(int l=k+1;l<=n-5;l++)
						for(int m=l+1;m<=n-4;m++)
							for(int o=m+1;o<=n-3;o++)
								for(int p=o+1;p<=n-2;p++)
									for(int q=p+1;q<=n-1;q++)
										for(int r=q+1;r<=n;r++){
											sum=a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]+a[r];
											maxx=max(a[i],max(a[j],max(a[k],max(a[l],max(a[m],max(a[o],max(a[p],max(a[q],a[r]))))))));
											if(sum>2*maxx){
												cnt++;
											}
										}
	if(side==10)
		for(int i=1;i<=n-9;i++)
			for(int j=i+1;j<=n-8;j++)
				for(int k=j+1;k<=n-7;k++)
					for(int l=k+1;l<=n-6;l++)
						for(int m=l+1;m<=n-5;m++)
							for(int o=m+1;o<=n-4;o++)
								for(int p=o+1;p<=n-3;p++)
									for(int q=p+1;q<=n-2;q++)
										for(int r=q+1;r<=n-1;r++)
											for(int s=r+1;s<=n;s++){
												sum=a[i]+a[j]+a[k]+a[l]+a[m]+a[o]+a[p]+a[q]+a[r]+a[s];
												maxx=max(a[i],max(a[j],max(a[k],max(a[l],max(a[m],max(a[o],max(a[p],max(a[q],max(a[r],a[s])))))))));
												if(sum>2*maxx){
													cnt++;
												}
											}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n<3){
		cout<<"0";
		return 0;
	}
	if(n==3){
		if(a[1]+a[2]+a[3]>2*a[3]){
			cout<<"1";
			return 0;
		}
		else{
			cout<<"0";
			return 0;
		}
	}
	for(int i=3;i<=n;i++){
		f(i);
	}
	cnt=cnt%998%244%353;
	cout<<cnt;
	return 0;
}
