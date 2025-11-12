#include <bits/stdc++.h>
using namespace std;
int a[1000000],b[1000000],c[100000],d[100000];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		int sum=0;
		int fmvp=0;
		int kpl=0;
		int liu=0;
		int qi=0;
		int yi=0;
		for(int i=0;i<n;i++){
			d[i]=max(a[i],max(b[i],c[i]));
			if(d[i]==a[i]){
				sum++;
			}
			else if(d[i]==b[i]){
				fmvp++;
			}
			else{
				kpl++;
			}
		}
		if(sum>n/2){
			for(int i=0;i<n;i++){
				if(liu>=a[i]){
					liu=a[i];
					qi=i;
				}
			}
			while(sum!=n/2){
				for(int i=0;i<n;i++){
					if(i==qi){
					    yi+=b[i]-a[i];
						sum--;
					}
				}
		    }
		}
		sum=0;
		fmvp=0;
		kpl=0;
		for(int i=0;i<n;i++){
			d[i]=max(a[i],max(b[i],c[i]));
			if(d[i]==a[i]){
				sum++;
			}
			else if(d[i]==b[i]){
				fmvp++;				
			}
			else{
				kpl++;
			}
		}
		liu=0;
		if(fmvp>n/2){
			for(int i=0;i<n;i++){
				if(liu>=b[i]){
					liu=b[i];
					qi=i;
				}
			}
			while(fmvp!=n/2){
				for(int i=0;i<n;i++){
					if(qi==i){
						yi+=c[i]-b[i];
						fmvp--;
					}
				}
			}
		}
		for(int i=0;i<n;i++){
			yi+=max(a[i],max(b[i],c[i]));	
		}
		cout<<yi;
	}
	return 0;
} 
