#include<bits/stdc++.h>
using namespace std;
struct student{
	int first;
	int cha;
	int zu;
};
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	int d[t],e=t;
	while(t--){
		int n,s=0;
		cin>>n;
		student w[n+1];
		for(int i=0;i<n;i++){
			int a[3];
			for(int j=0;j<3;j++) cin>>a[j]; 
			if(a[0]>=a[1]&&a[1]>=a[2]){
					w[i].first=a[0];
					w[i].zu=0;
					w[i].cha=a[0]-a[1];
			}
			else if(a[0]>=a[2]&&a[2]>=a[1]){
					w[i].first=a[0];
					w[i].zu=0;
					w[i].cha=a[0]-a[2];
			}
			else if(a[1]>=a[0]&&a[0]>=a[2]){
					w[i].first=a[1];
					w[i].zu=1;
					w[i].cha=a[1]-a[0];
			}
			else if(a[1]>=a[2]&&a[2]>=a[0]){
					w[i].first=a[1];
					w[i].zu=1;
					w[i].cha=a[1]-a[2];
			}
			else if(a[2]>=a[0]&&a[0]>=a[1]){
					w[i].first=a[2];
					w[i].zu=2;
					w[i].cha=a[2]-a[0];
			}
			else if(a[2]>=a[1]&&a[1]>=a[0]){
					w[i].first=a[2];
					w[i].zu=2;
					w[i].cha=a[2]-a[1];
			}
		}
		int a=0,b=0,c=0;
		for(int i=0;i<n;i++){
			s+=w[i].first;
			if(w[i].zu==0) a++;
			else if(w[i].zu==1) b++;
			else c++;
		}
		if(a<=n/2&&b<=n/2&&c<=n/2) d[t]=s;
		else{
			if(a>n/2){
				int cha[a],j=0;
				for(int i=0;i<n;i++){
					if(w[i].zu==0){
						cha[j]=w[i].cha;
						j++;
					}
				}
				sort(cha,cha+a);
				for(int i=0;i<a-n/2;i++) s-=cha[i];
				d[t]=s;
			}
			if(b>n/2){
				int cha[b],j=0;
				for(int i=0;i<n;i++){
					if(w[i].zu==1){
						cha[j]=w[i].cha;
						j++;
					}
				}
				sort(cha,cha+b);
				for(int i=0;i<b-n/2;i++) s-=cha[i];
				d[t]=s;
			}
			if(c>n/2){
				int cha[c],j=0;
				for(int i=0;i<n;i++){
					if(w[i].zu==2){
						cha[j]=w[i].cha;
						j++;
					}
				}
				sort(cha,cha+c);
				for(int i=0;i<c-n/2;i++) s-=cha[i];
				d[t]=s;
			}
		}
	}
	for(int i=e-1;i>=0;i--) cout<<d[i]<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
