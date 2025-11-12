#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
int t,n,a1[MAXN],a2[MAXN],a3[MAXN];
struct node{
	int v1,v2,v3;
	bool f=false;
	int o;
}a[MAXN];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].v1>>a[i].v2>>a[i].v3;
		}
		int sum1=0,sum2=0,sum3=0;
		int n_=n/2;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[i].v1<a[j].v1){
					int t1=a[i].v1;
					int t2=a[i].v2;
					int t3=a[i].v3;
					a[i].v1=a[j].v1;
					a[i].v2=a[j].v2;
					a[i].v3=a[j].v3;
					a[j].v1=t1;
					a[j].v2=t2;
					a[j].v3=t3;
				}
			}
		}
		for(int i=1;i<=n_;i++){
			sum1+=a[i].v1;
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[i].v2<a[j].v2){
					int t1=a[i].v1;
					int t2=a[i].v2;
					int t3=a[i].v3;
					a[i].v1=a[j].v1;
					a[i].v2=a[j].v2;
					a[i].v3=a[j].v3;
					a[j].v1=t1;
					a[j].v2=t2;
					a[j].v3=t3;
				}
			}
		}
		for(int i=1;i<=n_;i++){
			sum2+=a[i].v2;
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[i].v3<a[j].v3){
					int t1=a[i].v1;
					int t2=a[i].v2;
					int t3=a[i].v3;
					a[i].v1=a[j].v1;
					a[i].v2=a[j].v2;
					a[i].v3=a[j].v3;
					a[j].v1=t1;
					a[j].v2=t2;
					a[j].v3=t3;
				}
			}
		}
		for(int i=1;i<=n_;i++){
			sum3+=a[i].v3;
		}
		//for(int i=1;i<=n;i++){
		//	cout<<a[i].v1<<" "<<a[i].v2<<" "<<a[i].v3<<endl;
		//}cout<<sum1<<" "<<sum2<<" "<<sum3<<endl;
		int maxn=max(sum1,max(sum2,sum3));
		if(maxn==sum1){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(a[i].v1<a[j].v1){
						int t1=a[i].v1;
						int t2=a[i].v2;
						int t3=a[i].v3;
						a[i].v1=a[j].v1;
						a[i].v2=a[j].v2;
						a[i].v3=a[j].v3;
						a[j].v1=t1;
						a[j].v2=t2;
						a[j].v3=t3;
					}
				}
			}
			for(int i=1;i<=n_;i++){
				a[i].f=true;
			}
			for(int i=1;i<=n-n_;i++){
				a[n_+i].o=max(a[n_+i].v2,a[n_+i].v3);
			}
			for(int i=1;i<=n-n_;i++){
				sum1+=a[n_+i].o;
			}
			cout<<sum1<<endl;
		}
		if(maxn==sum2){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(a[i].v2<a[j].v2){
						int t1=a[i].v1;
						int t2=a[i].v2;
						int t3=a[i].v3;
						a[i].v1=a[j].v1;
						a[i].v2=a[j].v2;
						a[i].v3=a[j].v3;
						a[j].v1=t1;
						a[j].v2=t2;
						a[j].v3=t3;
					}
				}
			}
			for(int i=1;i<=n_;i++){
				a[i].f=true;
			}
			for(int i=1;i<=n-n_;i++){
				a[n_+i].o=max(a[n_+i].v1,a[n_+i].v3);
			}
			for(int i=1;i<=n-n_;i++){
				sum2+=a[n_+i].o;
			}
			cout<<sum2<<endl;
		}
		if(maxn==sum1){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(a[i].v3<a[j].v3){
						int t1=a[i].v1;
						int t2=a[i].v2;
						int t3=a[i].v3;
						a[i].v1=a[j].v1;
						a[i].v2=a[j].v2;
						a[i].v3=a[j].v3;
						a[j].v1=t1;
						a[j].v2=t2;
						a[j].v3=t3;
					}
				}
			}
			for(int i=1;i<=n_;i++){
				a[i].f=true;
			}
			for(int i=1;i<=n-n_;i++){
				a[n_+i].o=max(a[n_+i].v2,a[n_+i].v1);
			}
			for(int i=1;i<=n-n_;i++){
				sum3+=a[n_+i].o;
			}
			cout<<sum3<<endl;
		}
		
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
