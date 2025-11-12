#include<bits/stdc++.h>
using namespace std;
long long n,a[10000010],ans;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				int total=a[i]+a[j]+a[k];
				int maxn=max(a[i],max(a[j],a[k]));
				if(total>maxn*2)
					ans++;
				for(int b=k+1;b<=n;b++){
					int total=a[i]+a[j]+a[k]+a[b];
					int maxn=max(a[i],max(a[j],max(a[k],a[b])));
					if(total>maxn*2)
						ans++;
					for(int c=b+1;c<=n;c++){
						int total=a[i]+a[j]+a[k]+a[b]+a[c];
						int maxn=max(a[i],max(a[j],max(a[k],max(a[b],a[c]))));
						if(total>maxn*2)
							ans++;
						for(int d=c+1;d<=n;d++){
							int total=a[i]+a[j]+a[k]+a[b]+a[c]+a[d];
							int maxn=max(a[i],max(a[j],max(a[k],max(a[b],max(a[c],a[d])))));
							if(total>maxn*2)
								ans++;
							for(int e=d+1;e<=n;e++){
								int total=a[i]+a[j]+a[k]+a[b]+a[c]+a[d]+a[e];
								int maxn=max(a[i],max(a[j],max(a[k],max(a[b],max(a[c],max(a[d],a[e]))))));
								if(total>maxn*2)
									ans++;
								for(int f=e+1;f<=n;f++){
									int total=a[i]+a[j]+a[k]+a[b]+a[c]+a[d]+a[e]+a[f];
									int maxn=max(a[i],max(a[j],max(a[k],max(a[b],max(a[c],max(a[d],max(a[e],a[f])))))));
									if(total>maxn*2)
										ans++;
									for(int g=f+1;g<=n;g++){
										int total=a[i]+a[j]+a[k]+a[b]+a[c]+a[d]+a[e]+a[f]+a[g];
										int maxn=max(a[i],max(a[j],max(a[k],max(a[b],max(a[c],max(a[d],max(a[e],max(a[f],a[g]))))))));
										if(total>maxn*2)
											ans++;
										for(int h=g+1;h<=n;h++){
											int total=a[i]+a[j]+a[k]+a[b]+a[c]+a[d]+a[e]+a[f]+a[g]+a[h];
											int maxn=max(a[i],max(a[j],max(a[k],max(a[b],max(a[c],max(a[d],max(a[e],max(a[f],max(a[g],a[h])))))))));
											if(total>maxn*2)
												ans++;
											for(int l=h+1;l<=n;l++){
												int total=a[i]+a[j]+a[k]+a[b]+a[c]+a[d]+a[e]+a[f]+a[g]+a[h]+a[l];
												int maxn=max(a[i],max(a[j],max(a[k],max(a[b],max(a[c],max(a[d],max(a[e],max(a[f],max(a[g],max(a[h],a[l]))))))))));
												if(total>maxn*2)
													ans++;
												for(int m=l+1;m<=n;m++){
													int total=a[i]+a[j]+a[k]+a[b]+a[c]+a[d]+a[e]+a[f]+a[g]+a[h]+a[l]+a[m];
													int maxn=max(a[i],max(a[j],max(a[k],max(a[b],max(a[c],max(a[d],max(a[e],max(a[f],max(a[g],max(a[h],max(a[l],a[m])))))))))));
													if(total>maxn*2)
														ans++;
													for(int o=m+1;o<=n;o++){
														int total=a[i]+a[j]+a[k]+a[b]+a[c]+a[d]+a[e]+a[f]+a[g]+a[h]+a[l]+a[m]+a[o];
														int maxn=max(a[i],max(a[j],max(a[k],max(a[b],max(a[c],max(a[d],max(a[e],max(a[f],max(a[g],max(a[h],max(a[l],max(a[m],a[o]))))))))))));
														if(total>maxn*2)
															ans++;
														for(int p=o+1;p<=n;p++){
															int total=a[i]+a[j]+a[k]+a[b]+a[c]+a[d]+a[e]+a[f]+a[g]+a[h]+a[l]+a[m]+a[o]+a[p];
															int maxn=max(a[i],max(a[j],max(a[k],max(a[b],max(a[c],max(a[d],max(a[e],max(a[f],max(a[g],max(a[h],max(a[l],max(a[m],max(a[o],a[p])))))))))))));
															if(total>maxn*2)
																ans++;
															for(int q=p+1;q<=n;q++){
																int total=a[i]+a[j]+a[k]+a[b]+a[c]+a[d]+a[e]+a[f]+a[g]+a[h]+a[l]+a[m]+a[o]+a[p]+a[q];
																int maxn=max(a[i],max(a[j],max(a[k],max(a[b],max(a[c],max(a[d],max(a[e],max(a[f],max(a[g],max(a[h],max(a[l],max(a[m],max(a[o],max(a[p],a[q]))))))))))))));
																if(total>maxn*2)
																	ans++;
																for(int r=q+1;r<=n;r++){
																	int total=a[i]+a[j]+a[k]+a[b]+a[c]+a[d]+a[e]+a[f]+a[g]+a[h]+a[l]+a[m]+a[o]+a[p]+a[q]+a[r];
																	int maxn=max(a[i],max(a[j],max(a[k],max(a[b],max(a[c],max(a[d],max(a[e],max(a[f],max(a[g],max(a[h],max(a[l],max(a[m],max(a[o],max(a[p],max(a[q],a[r])))))))))))))));
																	if(total>maxn*2)
																		ans++;
																	for(int s=r+1;s<=n;s++){
																		int total=a[i]+a[j]+a[k]+a[b]+a[c]+a[d]+a[e]+a[f]+a[g]+a[h]+a[l]+a[m]+a[o]+a[p]+a[q]+a[r]+a[s];
																		int maxn=max(a[i],max(a[j],max(a[k],max(a[b],max(a[c],max(a[d],max(a[e],max(a[f],max(a[g],max(a[h],max(a[l],max(a[m],max(a[o],max(a[p],max(a[q],max(a[r],a[s]))))))))))))))));
																		if(total>maxn*2)
																			ans++;
																		for(int t=s+1;t<=n;t++){
																			int total=a[i]+a[j]+a[k]+a[b]+a[c]+a[d]+a[e]+a[f]+a[g]+a[h]+a[l]+a[m]+a[o]+a[p]+a[q]+a[r]+a[s]+a[t];
																			int maxn=max(a[i],max(a[j],max(a[k],max(a[b],max(a[c],max(a[d],max(a[e],max(a[f],max(a[g],max(a[h],max(a[l],max(a[m],max(a[o],max(a[p],max(a[q],max(a[r],max(a[s],a[t])))))))))))))))));
																			if(total>maxn*2)
																				ans++;
																			for(int u=t+1;u<=n;u++){
																				int total=a[i]+a[j]+a[k]+a[b]+a[c]+a[d]+a[e]+a[f]+a[g]+a[h]+a[l]+a[m]+a[o]+a[p]+a[q]+a[r]+a[s]+a[t]+a[u];
																				int maxn=max(a[i],max(a[j],max(a[k],max(a[b],max(a[c],max(a[d],max(a[e],max(a[f],max(a[g],max(a[h],max(a[l],max(a[m],max(a[o],max(a[p],max(a[q],max(a[r],max(a[s],max(a[t],a[u]))))))))))))))))));
																				if(total>maxn*2)
																					ans++;
																				for(int v=u+1;v<=n;v++){
																					int total=a[i]+a[j]+a[k]+a[b]+a[c]+a[d]+a[e]+a[f]+a[g]+a[h]+a[l]+a[m]+a[o]+a[p]+a[q]+a[r]+a[s]+a[t]+a[u]+a[v];
																					int maxn=max(a[i],max(a[j],max(a[k],max(a[b],max(a[c],max(a[d],max(a[e],max(a[f],max(a[g],max(a[h],max(a[l],max(a[m],max(a[o],max(a[p],max(a[q],max(a[r],max(a[s],max(a[t],max(a[u],a[v])))))))))))))))))));
																					if(total>maxn*2)
																						ans++;
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}}}}		
	cout<<ans;
	return 0;
}