//GZ-S00063 北京师范大学贵阳附属中学 刘祚诚 
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N],b[N],c[N];
int n;
int solve(int n){
	int q=n/2,w=n/2,e=n/2,sum1=0,sum2=0,sum3=0;
	for(int i=1;i<=n;i++){
		if(q!=0&&w!=0&&e!=0){
			if(a[i]>b[i]&&a[i]>c[i])sum1+=a[i],q--;
			if(b[i]>a[i]&&b[i]>c[i])sum1+=b[i],w--;
			if(c[i]>a[i]&&c[i]>b[i])sum1+=c[i],e--;			
		}else if(q==0&&w!=0&&e!=0){
			if(b[i]>c[i])sum1+=b[i],w--;
			else sum1+=c[i],e--;
		}else if(q!=0&&w==0&&e!=0){
			if(a[i]>c[i])sum1+=a[i],q--;
			else sum1+=c[i],e--;
		}else if(q!=0&&w!=0&&e==0){
			if(a[i]>b[i])sum1+=a[i],q--;
			else sum1+=b[i],w--;
		}
	}
	q=n/2,w=n/2,e=n/2;
	for(int i=n;i>=1;i--){
		if(q!=0&&w!=0&&e!=0){
			if(a[i]>b[i]&&a[i]>c[i])sum2+=a[i],q--;
			if(b[i]>a[i]&&b[i]>c[i])sum2+=b[i],w--;
			if(c[i]>a[i]&&c[i]>b[i])sum2+=c[i],e--;			
		}else if(q==0&&w!=0&&e!=0){
			if(b[i]>c[i])sum2+=b[i],w--;
			else sum2+=c[i],e--;
		}else if(q!=0&&w==0&&e!=0){
			if(a[i]>c[i])sum2+=a[i],q--;
			else sum2+=c[i],e--;
		}else if(q!=0&&w!=0&&e==0){
			if(a[i]>b[i])sum2+=a[i],q--;
			else sum2+=b[i],w--;
		}
	}
	q=n/2,w=n/2,e=n/2;
	for(int i=n/2+1,j=n/2;i<=n,j>=1;i++,j--){
		if(q!=0&&w!=0&&e!=0){
			if(a[i]>b[i]&&a[i]>c[i])sum3+=a[i],q--;
			if(b[i]>a[i]&&b[i]>c[i])sum3+=b[i],w--;
			if(c[i]>a[i]&&c[i]>b[i])sum3+=c[i],e--;			
		}else if(q==0&&w!=0&&e!=0){
			if(b[i]>c[i])sum3+=b[i],w--;
			else sum3+=c[i],e--;
		}else if(q!=0&&w==0&&e!=0){
			if(a[i]>c[i])sum3+=a[i],q--;
			else sum3+=c[i],e--;
		}else if(q!=0&&w!=0&&e==0){
			if(a[i]>b[i])sum3+=a[i],q--;
			else sum3+=b[i],w--;
		}
		if(q!=0&&w!=0&&e!=0){
			if(a[j]>b[j]&&a[j]>c[j])sum3+=a[j],q--;
			if(b[j]>a[j]&&b[j]>c[j])sum3+=b[j],w--;
			if(c[j]>a[j]&&c[j]>b[j])sum3+=c[j],e--;			
		}else if(q==0&&w!=0&&e!=0){
			if(b[j]>c[j])sum3+=b[j],w--;
			else sum3+=c[j],e--;
		}else if(q!=0&&w==0&&e!=0){
			if(a[j]>c[j])sum3+=a[j],q--;
			else sum3+=c[j],e--;
		}else if(q!=0&&w!=0&&e==0){
			if(a[j]>b[j])sum3+=a[j],q--;
			else sum3+=b[j],w--;
		}
	}
	return max(sum3,max(sum1,sum2));
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		int suma,sumb,sumc;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			suma+=a[i],sumb+=b[i],sumc+=c[i];
		}
		if(sumb==sumc==0){
			int summ=0;
			sort(a+1,a+n+1);
			for(int i=n;i>n/2;i--)summ+=a[i];
			cout<<summ<<endl;
			continue;
		}else if(sumc==0){
			int ssum;
			sort(a+1,a+n+1);
			for(int i=n;i>0;i--)ssum+=max(a[i],b[i]);
			cout<<ssum<<endl;
			continue;
		}
		int sum=solve(n);
		cout<<sum<<endl;
	}
	return 0;
}

