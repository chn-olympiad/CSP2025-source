#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int a[5005];
int s[5005];
int dp[5005];
int c[5005];
int ma;
int ss;
int mod1=998244353;
int jc(int x){
	int s=1;
	for(int i=1;i<=x;i++){
		s=s*i%mod1;
	}
	return s;
}
bool cmp(int a1,int b1){
	return a1>b1;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<=3){
		int ma;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			s[i]=s[i-1]+a[i];
			ma=max(ma,a[i]);
		}
		if(n==3){
			if(a[1]+a[2]+a[3]>ma*2) ss++;
		}
		cout<<ss<<endl;
	}
	else {
		bool f=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]>1) f=1;
		}
		if(f==0){
			int s1=1;
			for(int i=1;i<n;i++){
				s1=s1*i%mod1;
				ss=(ss+(jc(n))/s1%mod1)%mod1;
			}
			cout<<ss<<endl;
		}
		else{
			if(n<=8){
				for(int i=1;i<=n;i++){
					for(int j=i+1;j<=n;j++){
						for(int k=j+1;k<=n;k++){
							int ma=0;
							ma=max(a[k],max(a[i],a[j]));
							if(a[i]+a[j]+a[k]>ma*2){
								ss++;
								ss%=mod1;
							}
						} 
					}
				}
				for(int i=1;i<=n;i++){
					for(int j=i+1;j<=n;j++){
						for(int k=j+1;k<=n;k++){
							for(int b=k+1;b<=n;b++){
								int ma=0;
								ma=max(a[b],max(a[k],max(a[i],a[j])));
								if(a[i]+a[j]+a[k]+a[b]>ma*2){
									ss++;
									ss%=mod1;
								}
							}
							
						} 
					}
				}
				for(int i=1;i<=n;i++){
					for(int j=i+1;j<=n;j++){
						for(int k=j+1;k<=n;k++){
							for(int b=k+1;b<=n;b++){
								for(int c=b+1;c<=n;c++){
									int ma=0;
									ma=max(a[c],max(a[b],max(a[k],max(a[i],a[j]))));
									if(a[i]+a[j]+a[k]+a[b]+a[c]>ma*2){
										ss++;
										ss%=mod1;
									}
								}
								
							}
							
						} 
					}
				}
				for(int i=1;i<=n;i++){
					for(int j=i+1;j<=n;j++){
						for(int k=j+1;k<=n;k++){
							for(int b=k+1;b<=n;b++){
								for(int c=b+1;c<=n;c++){
									for(int d=c+1;d<=n;d++){
										int ma=0;
										ma=max(a[d],max(a[c],max(a[b],max(a[k],max(a[i],a[j])))));
										if(a[i]+a[j]+a[k]+a[b]+a[c]+a[d]>ma*2){
											ss++;
											ss%=mod1;
										}
									}
								}
								
							}
							
						} 
					}
				}
				for(int i=1;i<=n;i++){
					for(int j=i+1;j<=n;j++){
						for(int k=j+1;k<=n;k++){
							for(int b=k+1;b<=n;b++){
								for(int c=b+1;c<=n;c++){
									for(int d=c+1;d<=n;d++){
										for(int e=d+1;e<=n;e++){
											int ma=0;
											ma=max(a[e],max(a[d],max(a[c],max(a[b],max(a[k],max(a[i],a[j]))))));
											if(a[i]+a[j]+a[k]+a[b]+a[c]+a[d]+a[e]>ma*2){
												ss++;
												ss%=mod1;
											}
										}
										
									}
								}
								
							}
							
						} 
					}
				}
				for(int i=1;i<=n;i++){
					for(int j=i+1;j<=n;j++){
						for(int k=j+1;k<=n;k++){
							for(int b=k+1;b<=n;b++){
								for(int c=b+1;c<=n;c++){
									for(int d=c+1;d<=n;d++){
										for(int e=d+1;e<=n;e++){
											for(int h=e+1;h<=n;h++){
												int ma=0;
												ma=max(a[h],max(a[e],max(a[d],max(a[c],max(a[b],max(a[k],max(a[i],a[j])))))));
												if(a[h]+a[i]+a[j]+a[k]+a[b]+a[c]+a[d]+a[e]>ma*2){
													ss++;
													ss%=mod1;
												}
											}
										}
										
									}
								}
								
							}
							
						} 
					}
				}
				cout<<ss<<endl;
			}
		}
	}
	return 0;
}
