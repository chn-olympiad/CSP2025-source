#include<bits/stdc++.h>
using namespace std;
int T;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		int n=0,a[10005],b[10005],c[10005],d[10005],al=0,bl=0,sum=0,cl=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			d[i]=max(a[i],b[i])-min(a[i],b[i]);
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<n;j++){
				if(d[j]<d[j+1]){
					swap(d[j],d[j+1]);
					swap(a[j],a[j+1]);
					swap(b[j],b[j+1]);
				}
			}
		}
		for(int i=1;i<=n;i++){
			if(a[i]>b[i]&&a[i]>c[i]&&al<=n/2){
				al++;
				sum+=a[i];
			}else if(b[i]>c[i]&&b[i]>c[i]&&bl<=n/2){
				bl++;
				sum+=b[i];
				
			}else if(a[i]>b[i]&&a[i]>c[i]&&cl<=n/2){
				cl++;
				sum+=c[i];
			}
		}
		cout<<sum;
	}	
}



