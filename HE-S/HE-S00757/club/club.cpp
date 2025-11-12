#include<bits/stdc++.h>
using namespace std;
int t,n,a[10086],b[10086],c[10086],sum,d,e[3],f;
vector<int>x;
vector<int>y;
vector<int>z;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		sort(a,a+n);
		sort(b,b+n);
		sort(c,c+n);
		for(int i=0;i<n;i++){
			e[0]=a[i];
			e[1]=b[i];
			e[2]=c[i];
			d=max(a[i],b[i]);
			d=max(d,c[i]);
			if(a[i]<b[i] and b[i]<c[i])b[i]=f;
			if(a[i]<b[i] and b[i]>c[i])b[i]=f;
			if(a[i]<b[i] and b[i]>c[i] and a[i]>c[i])c[i]=f;
			if(a[i]>b[i] and a[i]<c[i] )a[i]=f;
			if(a[i]>b[i] and a[i]>c[i] and b[i]<c[i])c[i]=f;
			if(a[i]>b[i] and a[i]>c[i] and b[i]>c[i])b[i]=f;
			for(int i=0;i<=2;i++){
				if(d==e[i]){
					if(i==0){
						if(x.size()>=n/2){
							for(int j=0;j<=2;j++){
								if(f==e[j]){
									if(j==0){
										y.push_back(e[j]);
									}
									if(j==1){
										y.push_back(e[j]);
									}
									if(j==2){
										z.push_back(e[j]);
									}
								}
							}
						}
						x.push_back(e[i]);
					}
					if(i==1){
						if(y.size()>=n/2){
							for(int j=0;j<=2;j++){
								if(f==e[j]){
									if(j==0){
										y.push_back(e[j]);
									}
									if(j==1){
										y.push_back(e[j]);
									}
									if(j==2){
										z.push_back(e[j]);
									}
								}
							}
						}
						y.push_back(e[i]);
					}
					if(i==2){
						if(z.size()>=n/2){
							for(int j=0;j<=2;j++){
								if(f==e[j]){
									if(j==0){
										y.push_back(e[j]);
									}
									if(j==1){
										y.push_back(e[j]);
									}
									if(j==2){
										z.push_back(e[j]);
									}
								}
							}
						}
						z.push_back(e[i]);
					}
				}
			}
			f=0;
			d=0;
		}
		for(int i=0;i<=x.size();i++){
			sum+=x[i];
		}
		for(int i=0;i<=y.size();i++){
			sum+=y[i];
		}
		for(int i=0;i<=z.size();i++){
			sum+=z[i];
		}
		cout<<sum;
		x.clear();
		y.clear();
		z.clear();
		sum=0;
		
	}
	return 0;
}
