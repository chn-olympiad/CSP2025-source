#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],sum=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int b=1;b<=n;b++){
		for(int c=b+1;c<=n;c++){
			for(int d=c+1;d<=n;d++){
				for(int e=d+1;e<=n;e++){
					for(int f=e+1;f<=n;f++){
						for(int g=f+1;g<=n;g++){
							for(int h=g+1;h<=n;h++){
								for(int i=h+1;i<=n;i++){
										for(int j=i+1;j<=n;j++){
												for(int k=j+1;k<=n;k++){
													int m=max(max(max(max(max(max(max(max(max(a[b],a[c]),a[d]),a[e]),a[f]),a[g]),a[h]),a[i]),a[j]),a[k]);
													if((a[b]+a[c]+a[d]+a[e]+a[f]+a[g]+a[h]+a[i]+a[j]+a[k])>2*m){
														sum++;
													}
												}
											int m=max(max(max(max(max(max(max(max(a[b],a[c]),a[d]),a[e]),a[f]),a[g]),a[h]),a[i]),a[j]);
											if((a[b]+a[c]+a[d]+a[e]+a[f]+a[g]+a[h]+a[i]+a[j])>2*m){
												sum++;
											}
										}
									int m=max(max(max(max(max(max(max(a[b],a[c]),a[d]),a[e]),a[f]),a[g]),a[h]),a[i]);
									if((a[b]+a[c]+a[d]+a[e]+a[f]+a[g]+a[h]+a[i])>2*m){
										sum++;
									}
								}
								int m=max(max(max(max(max(max(a[b],a[c]),a[d]),a[e]),a[f]),a[g]),a[h]);
								if((a[b]+a[c]+a[d]+a[e]+a[f]+a[g]+a[h])>2*m){
									sum++;
								}
							}
							int m=max(max(max(max(max(a[b],a[c]),a[d]),a[e]),a[f]),a[g]);
							if((a[b]+a[c]+a[d]+a[e]+a[f]+a[g])>2*m){
								sum++;
							}
						}
						int m=max(max(max(max(a[b],a[c]),a[d]),a[e]),a[f]);
						if((a[b]+a[c]+a[d]+a[e]+a[f])>2*m){
							sum++;
						}
					}
					int m=max(max(max(a[b],a[c]),a[d]),a[e]);
					if((a[b]+a[c]+a[d]+a[e])>2*m){
						sum++;
					}
				}
				int m=max(max(a[b],a[c]),a[d]);
				if((a[b]+a[c]+a[d])>2*m){
					sum++;
				}
			}
		}
	}
	cout<<sum;
	return 0;
}
