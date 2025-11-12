#include<bits/stdc++.h>
using namespace std;
struct a{
	int fi,se,th;
}a[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t>0){
		t-=1;
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].fi>>a[i].se>>a[i].th;
		}
		int sw=1;
		for(int I=1;I<=n&&sw;I++){
			sw=0;
			for(int i=1;i<n;i++){
				if(a[i+1].fi!=a[i].fi){
					if(a[i+1].fi>a[i].fi&&a[i+1].fi>=a[i+1].se&&a[i+1].fi>=a[i+1].th){
						swap(a[i],a[i+1]);
						sw++;
					}
					else if(a[i+1].fi<a[i].fi&&(a[i+1].fi>=a[i+1].se||a[i+1].fi>=a[i+1].th)){
						swap(a[i],a[i+1]);
						sw++;
					}
				}
				else{
					if(a[i+1].se!=a[i].se){
						if(a[i+1].se>a[i].se&&a[i+1].se>=a[i+1].fi&&a[i+1].se>=a[i+1].th){
							swap(a[i],a[i+1]);
							sw++;
						}
						else if(a[i+1].se<a[i].se&&(a[i+1].se>=a[i+1].fi||a[i+1].se>=a[i+1].th)){
							swap(a[i],a[i+1]);
							sw++;
						}
					}
					else{
						if(a[i+1].th>a[i].th&&a[i+1].th>=a[i+1].fi&&a[i+1].th>=a[i+1].se){
							swap(a[i],a[i+1]);
							sw++;
						}
						else if(a[i+1].th<a[i].th&&(a[i+1].th>=a[i+1].fi||a[i+1].th>=a[i+1].se)){
							swap(a[i],a[i+1]);
							sw++;
						}
					}
				}
			}
		}
		long long sum=0;
		int x=0,y=0,z=0;
		for(int i=1;i<=n;i++){
			if(a[i].fi>a[i].se&&a[i].fi>a[i].th&&x<n/2||y>=n/2&&a[i].fi>=a[i].th||z>=n/2&&a[i].fi>=a[i].se){
				sum+=a[i].fi;
				x++;
			}
			else if(a[i].se>a[i].fi&&a[i].se>a[i].th&&y<n/2||x>=n/2&&a[i].se>=a[i].th||z>=n/2&&a[i].se>=a[i].fi){
				sum+=a[i].se;
				y++;
			}
			else if(a[i].th>a[i].fi&&a[i].th>a[i].se&&z<n/2||x>=n/2&&a[i].th>=a[i].se||y>=n/2&&a[i].th>=a[i].fi){
				sum+=a[i].th;
				z++;
			}
		}
		int max1=sum;
		sum=0;
		x=0,y=0,z=0;
		for(int i=n;i>=1;i--){
			if(a[i].fi>a[i].se&&a[i].fi>a[i].th&&x<n/2||y>=n/2&&a[i].fi>=a[i].th||z>=n/2&&a[i].fi>=a[i].se){
				sum+=a[i].fi;
				x++;
			}
			else if(a[i].se>a[i].fi&&a[i].se>a[i].th&&y<n/2||x>=n/2&&a[i].se>=a[i].th||z>=n/2&&a[i].se>=a[i].fi){
				sum+=a[i].se;
				y++;
			}
			else if(a[i].th>a[i].fi&&a[i].th>a[i].se&&z<n/2||x>=n/2&&a[i].th>=a[i].se||y>=n/2&&a[i].th>=a[i].fi){
				sum+=a[i].th;
				z++;
			}
		}
		if(max1>sum){
			sum=max1;
		}
		cout<<sum<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
