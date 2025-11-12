#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int a[500005];
int n;
int summ[500005];
void s(bool f[],int sum,int maxx,int x){
	for(int i=x+1;i<=n;i++){
//		cout<<"个数="<<i<<endl;
		for(int j=1;j<=n;j++){
			if(!f[j]){
				maxx=max(maxx,a[j]);
				if(sum+a[j]>maxx*2){
					summ[i]++;
					f[j]=true;
//					cout<<"新的数的下标="<<j<<endl;
					s(f,sum+a[j],maxx,i);
				}
			}
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
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int z=j+1;z<=n;z++){
				if((a[i]+a[j]+a[z])>a[z]*2){
//					cout<<"i="<<i<<" j="<<j<<" z="<<z<<endl;
					summ[3]++;
					bool f[n+5];
					memset(f,false,sizeof(f));
					f[i]=true;f[j]=true;f[z]=true;
					s(f,a[i]+a[j]+a[z],a[z],3);
				}
			}
		}
	}
//	cout<<"summ[3]="<<summ[3]<<endl;
	int ans=0;
	for(int i=3;i<=n;i++){
		ans+=summ[i];
	}
	cout<<ans<<endl;
//	for(int i=1;i<=n;i++){
//		int sum=0;
//		for(int j=i;j<=n;j++){
//			sum+=a[j];
//			if(sum>a[j]*2&&(j-i+1)>=3){
//				cout<<"i="<<i<<" j="<<j<<endl;
//				ans++;
//			}
//		}
//	}
//	cout<<ans<<endl;
	return 0;
}
