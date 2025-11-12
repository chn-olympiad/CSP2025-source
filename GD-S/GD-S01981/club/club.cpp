#include<bits/stdc++.h>
using namespace std;
long long a[100010],b[100010],c[100010],d[100010],ans;
bool flag=true;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		long long n,num=0,sum;
		cin>>n;
		sum=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(b[i]!=0 or c[i]!=0) flag=false;
			d[i]=i;
		}
		if(flag){
			sort(a+1,a+n+1);
			for(int i=n;i>=sum;i--){
				ans+=a[i];
			}
			cout<<ans<<endl;
			continue;
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[i]<a[j]) swap(a[i],a[j]),swap(d[i],d[j]),swap(b[i],b[j]),swap(c[i],c[j]);
			}
		}
		for(int i=1;i<=n;i++){
			if(sum<=num) break;
			
			if(a[i]>b[i] and a[i]>c[i]){
				a[d[i]]=-1,b[d[i]]=-1,c[d[i]]=-1,d[i]=0;
				num++;
				ans+=a[i];
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(b[i]<b[j]) swap(d[i],d[j]),swap(b[i],b[j]),swap(c[i],c[j]);
			}
		}
		num=0;
		for(int i=1;i<=n;i++){
			if(sum<=num or b[i]==-1) break;
			//cout<<i<<" "<<a[i]<<" "<<b[i]<<" "<<c[i]<<" "<<d[i]<<endl;
			if(b[i]>c[i]){
				c[d[i]]=-1;
				num++;
				ans+=b[i];
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(c[i]<c[j]) swap(d[i],d[j]),swap(c[i],c[j]);
			}
		}
		num=0;
		for(int i=1;i<=n;i++){
			if(sum<=num or c[i]==-1) break;
			ans+=c[i];
			num++;
		}
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}
