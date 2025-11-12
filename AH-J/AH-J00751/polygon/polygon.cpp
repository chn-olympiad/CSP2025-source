#include<bits/stdc++.h>
using namespace std;
int n,a[5010];
int ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		
	}
	sort(a+1,a+n+1);
	int x[10];
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				x[1]=a[i]+a[j];
				if(x[1]>a[k])ans++;
				for(int l=k+1;l<=n;l++){
					x[2]=x[1]+a[k];
					if(x[2]>a[l])ans++;
					for(int b=l+1;b<=n;b++){
						x[3]=x[2]+a[l];
						if(x[3]>a[b])ans++;
						for(int c=b+1;c<=n;c++){
							x[4]=x[3]+a[b];
							if(x[4]>a[c])ans++;
							for(int d=c+1;d<=n;d++){
								x[5]=x[4]+a[c];
								if(x[5]>a[d])ans++;
								for(int e=d+1;e<=n;e++){
									x[6]=x[5]+a[d];
									if(x[6]>a[e])ans++;
									for(int f=e+1;f<=n;f++){
										x[7]=x[6]+a[e];
										if(x[7]>a[f])ans++;
										for(int g=f+1;g<=n;g++){
											x[8]=x[7]+a[f];
											if(x[8]>a[g])ans++;
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
	cout<<ans;
	return 0;
}
