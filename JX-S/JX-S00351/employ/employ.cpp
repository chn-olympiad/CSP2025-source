#include <bits/stdc++.h>
using namespace std;
int a[10005];
int b[10005];
int c[10005];

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			cin>>b[i];
			cin>>c[i];
		}
		int maxpep=n/2;
		int apep=0;
		int bpep=0;
		int cpep=0;
		int aqq=0;
		int bqq=0;
		int cqq=0;
		for(int i=1;i<=n;i++){
			//A
			if(a[i]>b[i]&&a[i]>c[i]&&apep<=maxpep){
				aqq+=a[i];
				apep++;
			}else if(a[i]>b[i]&&a[i]>c[i]&&apep>maxpep){
				if(b[i]>c[i]&&bpep<=maxpep){
				bqq+=b[i];
				bpep++;
				}else{
					cqq+=c[i];
					cpep++;
				}
			}
			//B
			if(b[i]>a[i]&&b[i]>c[i]&&bpep<=maxpep){
				bqq+=b[i];
				bpep++;
			}else if(b[i]>a[i]&&b[i]>c[i]&&bpep>maxpep){
				if(a[i]>c[i]&&apep<=maxpep){
				aqq+=a[i];
				apep++;
				}else{
					cqq+=c[i];
					cpep++;
				}
			}
			//c
			if(c[i]>a[i]&&c[i]>b[i]&&cpep<=maxpep){
				cqq+=c[i];
				cpep++;
			}else if(c[i]>a[i]&&c[i]>b[i]&&cpep>maxpep){
				if(a[i]>b[i]&&apep<=maxpep){
				aqq+=a[i];
				apep++;
				}else{
					bqq+=b[i];
					bpep++;
				}
			}
			
			
			
		}
		cout<<aqq+bqq+cqq<<endl;
	}
	return 0;
}
