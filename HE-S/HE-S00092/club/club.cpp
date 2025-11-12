#include<bits/stdc++.h>
using namespace std;
long long t,n,a[100050],b[100050],c[100050],ans[100050],aa,bb,cc,nn[100050],e,anss,f;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >>t;
	while(t--){
		cin >>n;
		for (int i=1;i<=n;i++){
			cin >>a[i]>>b[i]>>c[i];
		}
		for (int i=1;i<=n;i++){
			ans[i]=max(a[i],max(b[i],c[i]));
			if(ans[i]==a[i]){
				aa++;
				if (aa>(n/2)){
					anss=ans[1];
					e=max(b[i],c[i]);
					for (int j=1;j<i;j++){
						if(b[j]+a[i]>anss && c[j]+a[i]<b[j]+a[i]){
							anss=b[j]+a[i];
							e=b[j];
							f=j;
						}
						else{
							anss=c[j]+a[i];
							e=c[j];
							f=j;
						}
					}
					ans[f]=e;
				}
			}
			if(ans[i]==b[i]){
				bb++;
				if (bb>(n/2)){
					e=max(a[i],c[i]);
					anss=ans[1];
					for (int j=1;j<=i;j++){
						if(a[j]+b[i]>anss && c[j]+b[i]<a[j]+b[i]){
							anss=a[j]+b[i];
							e=a[j];
							f=j;
						}
						else{
							anss=c[j]+b[i];
							e=c[j];
							f=j;
						}
					}
					ans[f]=e;
				}
			}
			if(ans[i]==c[i]){
				cc++;
				if (cc>(n/2)){
					e=max(b[i],a[i]);
					anss=ans[1];
					for (int j=1;j<=i;j++){
						if(a[j]+c[i]>anss && b[j]+c[i]<a[j]+c[i]){
							anss=a[j]+c[i];
							e=a[j];
							f=j;
						}
						else{
							anss=b[j]+c[i];
							e=b[j];
							f=j;
						}
					}
					ans[f]=e;
				}
			}
		}
		aa=0;
		bb=0;
		cc=0;
		for (int i=1;i<=n;i++){
			nn[t+1]+=ans[i];
		}
	}
	for (int i=3;i>=1;i--){
		cout <<nn[i]<<endl;
	}
	return 0;
}
