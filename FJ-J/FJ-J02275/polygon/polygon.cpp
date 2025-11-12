#include<bits/stdc++.h>
using namespace std;
long long n,a[5010],max1=-1,b[5010],z,ans,s[5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		max1=max(max1,a[i]);
		s[a[i]]++;
	}	
	if(n<3){
		cout<<0;
		return 0;
	}else{
		if(n==3){
			for(int i=1;i<=n;i++)
				z+=a[i];
			if(z>2*max1){
				cout<<1;
				return 0;
			}else{
				cout<<0;
				return 0;
			}
		}else{
			for(int i=1;i<=n;i++)
				b[a[i]]=-1;
			for(int i=1;i<=n;i++){
				for(int ii=1;ii<=n;ii++){
					for(int iii=1;iii<=n;iii++){
						for(int iiii=1;iiii<=n;iiii++){
							for(int iiiii=1;iiiii<=n;iiiii++){
								b[a[i]]+=2;
								b[a[ii]]+=2;
								b[a[iii]]+=2;
								b[a[iiii]]+=2;
								b[a[iiiii]]+=2;	
								long long max2=-1,z2,max3=-1,z3,p=0,p1=0,k;
								for(int j=1;j<=n;j++){
									if(b[a[j]]>0&&(b[a[j]]+1)/2<=s[a[j]]){
										max2=max(max2,a[j]);
										z2+=a[j];
										p++;
										k=1;
									}
									if(b[a[j]]==-1&&(b[a[j]]+1)/2<=s[a[j]]){
										max3=max(max3,a[j]);
										z3+=a[j];
										p1++;
										k=1;
									}
								}
								if(z2>2*max2&&p>=3&&k==1){
									ans=(ans+1)%998244353;
								}
								if(z3>2*max3&&p1>=3&&k==1){
									ans=(ans+1)%998244353;
								}
								for(int j=1;j<=n;j++)
									b[a[j]]=-1;
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
