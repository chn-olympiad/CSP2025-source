#include<bits/stdc++.h>
using namespace std;
long long t,n,a[100100],b[100100],c[100100],num1,num2,num3,ans,zz;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int iii=1;iii<=t;iii++){
		cin>>n;
		ans=0;num1=0;num2=0;num3=0;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]>=b[i]&&a[i]>=c[i]){
				ans+=a[i];
				num1++;
			}
			if(b[i]>=a[i]&&b[i]>=c[i]){
				ans+=b[i];
				num2++;
			}
			if(c[i]>=a[i]&&c[i]>=b[i]){
				ans+=c[i];
				num3++;
			}
			if(a[i]==b[i]&&a[i]==c[i])ans-=2*a[i];
			else if(a[i]==b[i])ans-=a[i];
			else if(c[i]==b[i])ans-=c[i];
			else if(a[i]==c[i])ans-=a[i];
		}
		//cout<<num1<<' '<<num2<<' '<<num3<<endl;
		if(num1>num2&&num1>num3){
			int temp[100100];
			zz=1;
			for(int i=1;i<=n;i++){
				if(a[i]>=b[i]&&a[i]>=c[i]){
					temp[zz]=min(a[i]-b[i],a[i]-c[i]);
					zz++;
				}
			}
			sort(temp+1,temp+zz);
			for(int i=1;i<=num1-n/2;i++)ans-=temp[i];
		}
		if(num2>num1&&num2>num3){
			int temp[100100];
			zz=1;
			for(int i=1;i<=n;i++){
				if(b[i]>=a[i]&&b[i]>=c[i]){
					temp[zz]=min(b[i]-a[i],b[i]-c[i]);
					zz++;
				}
			}
			sort(temp+1,temp+zz);
			for(int i=1;i<=num2-n/2;i++)ans-=temp[i];
		}
		if(num3>num1&&num3>num2){
			int temp[100100];
			zz=1;
			for(int i=1;i<=n;i++){
				if(c[i]>=a[i]&&c[i]>=b[i]){
					temp[zz]=min(c[i]-b[i],c[i]-a[i]);
					zz++;
				}
			}
			/*for(int i=1;i<=zz;i++){
				cout<<i<<' '<<temp[i]<<endl;
			}*/
			sort(temp+1,temp+zz);
			for(int i=1;i<=num3-n/2;i++)ans-=temp[i];
		}
		cout<<ans<<endl;
	}
	return 0;
} 
