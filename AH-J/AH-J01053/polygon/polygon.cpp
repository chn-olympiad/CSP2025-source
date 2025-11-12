#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353,N=5e3+5;
int a[N];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	if(n<=3){
		if(a[1]+a[2]>a[3])
			cout<<1;
		else cout<<0;
	}else if(n<=10){
		int cnt=0;
		if(n>=3){
			for(int i=1;i<=n;i++)
				for(int j=i+1;j<=n;j++)
					for(int k=j+1;k<=n;k++)
						if(a[i]+a[j]+a[k]>a[k]*2)
							cnt++;
		}if(n>=4){
			for(int i1=1;i1<=n;i1++)
				for(int i2=i1+1;i2<=n;i2++)
					for(int i3=i2+1;i3<=n;i3++)
						for(int i4=i3+1;i4<=n;i4++)
							if(a[i1]+a[i2]+a[i3]+a[i4]>a[i4]*2)
								cnt++;
		}if(n>=5){
			for(int i1=1;i1<=n;i1++)
				for(int i2=i1+1;i2<=n;i2++)
					for(int i3=i2+1;i3<=n;i3++)
						for(int i4=i3+1;i4<=n;i4++)
							for(int i5=i4+1;i5<=n;i5++)
								if(a[i1]+a[i2]+a[i3]+a[i4]+a[i5]>a[i5]*2)
									cnt++;
		}if(n>=6){
			for(int i1=1;i1<=n;i1++)
				for(int i2=i1+1;i2<=n;i2++)
					for(int i3=i2+1;i3<=n;i3++)
						for(int i4=i3+1;i4<=n;i4++)
							for(int i5=i4+1;i5<=n;i5++)
								for(int i6=i5+1;i6<=n;i6++)
									if(a[i1]+a[i2]+a[i3]+a[i4]+a[i5]+a[i6]>a[i6]*2)
										cnt++;
		}if(n>=7){
			for(int i1=1;i1<=n;i1++)
				for(int i2=i1+1;i2<=n;i2++)
					for(int i3=i2+1;i3<=n;i3++)
						for(int i4=i3+1;i4<=n;i4++)
							for(int i5=i4+1;i5<=n;i5++)
								for(int i6=i5+1;i6<=n;i6++)
									for(int i7=i6+1;i7<=n;i7++)
										if(a[i1]+a[i2]+a[i3]+a[i4]+a[i5]+a[i6]+a[i7]>a[i7]*2)
											cnt++;
		}if(n>=8){
			for(int i1=1;i1<=n;i1++)
				for(int i2=i1+1;i2<=n;i2++)
					for(int i3=i2+1;i3<=n;i3++)
						for(int i4=i3+1;i4<=n;i4++)
							for(int i5=i4+1;i5<=n;i5++)
								for(int i6=i5+1;i6<=n;i6++)
									for(int i7=i6+1;i7<=n;i7++)
										for(int i8=i7+1;i8<=n;i8++)
											if(a[i1]+a[i2]+a[i3]+a[i4]+a[i5]+a[i6]+a[i7]+a[i8]>a[i8]*2)
												cnt++;
		}if(n>=9){
			for(int i1=1;i1<=n;i1++)
				for(int i2=i1+1;i2<=n;i2++)
					for(int i3=i2+1;i3<=n;i3++)
						for(int i4=i3+1;i4<=n;i4++)
							for(int i5=i4+1;i5<=n;i5++)
								for(int i6=i5+1;i6<=n;i6++)
									for(int i7=i6+1;i7<=n;i7++)
										for(int i8=i7+1;i8<=n;i8++)
											for(int i9=i8+1;i9<=n;i9++)
												if(a[i1]+a[i2]+a[i3]+a[i4]+a[i5]+a[i6]+a[i7]+a[i8]+a[i9]>a[i9]*2)
													cnt++;
		}if(n>=10){
			if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]+a[10]>a[10]*2)
				cnt++;
		}
		cout<<cnt;
	}
	else{
		int x=n*(n-1LL)/2LL+n+1LL;
		int ans=1LL;
		for(int i=1;i<=n;i++)
			ans=(ans*2LL)%mod;
		cout<<(ans-x)%mod;
	}
	return 0;
}
