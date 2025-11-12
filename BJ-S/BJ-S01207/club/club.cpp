#include<bits/stdc++.h>
using namespace std;
long long t,n,a[100005],b[100005],c[100005],d[100005],num=0,f=1;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int z=1;z<=t;z++){
		num=0;
		f=1;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if((a[i]!=0&&b[i]!=0)||(c[i]!=0&&b[i]!=0)||(a[i]!=0&&c[i]!=0)){
				f=0;
			}
			if((a[i]>=b[i]&&b[i]>=c[i])||(a[i]>=c[i]&&c[i]>=b[i])){
				d[i]=a[i];
			}
			else if((b[i]>=a[i]&&a[i]>=c[i])||(b[i]>=c[i]&&c[i]>=a[i])){
				d[i]=b[i];
			}
			else{
				d[i]=c[i];
			}
		}
		sort(d+1,d+n+1);
		if(f==0){
			for(int j=n;j>=1;j--){
				num+=d[j];
			}
		}
		else{
			for(int j=n;j>=n/2+1;j--){
				num+=d[j];
			}
		}
		cout<<num;
	}
	return 0;
}
