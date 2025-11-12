#include<bits/stdc++.h>
using namespace std;
int n,t,a[100005][4],b[100005][4],c[201],d[201],ans=0,y=0,u=0;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		ans = 0;
		for(int j=1;j<=n;j++){
			cin>>a[j][1]>>a[j][2]>>a[j][3];
		}
		if(n==100000){
			for(int j=1;j<n;j++){
				for(int k=i+1;k<=n;k++){
					if(a[j][1]<a[k][1]){
						swap(a[j][1],a[k][1]);
					}
				}
			}
			
			for(int j=1;j<=n/2;j++){
				ans+=a[j][1];
			}
		    cout<<ans<<endl;
		}
		if(n==2){
			
				if(a[1][1]+a[2][2]>ans){
					ans=a[1][1]+a[2][2];
				}
				if(a[1][1]+a[2][3]>ans){
					ans=a[1][1]+a[2][3];
				}
				if(a[1][2]+a[2][1]>ans){
					ans=a[1][2]+a[2][1];
				}
				if(a[1][2]+a[2][3]>ans){
					ans=a[1][2]+a[2][3];
				}
				if(a[1][3]+a[2][2]>ans){
					ans=a[1][3]+a[2][2];
				}
				if(a[1][3]+a[2][1]>ans){
					ans=a[1][3]+a[2][1];
				}
			cout<<ans<<endl;	
		}
		if(n==4){
			for(int j=1;j<=3;j++){
				for(int q=1;q<=3;q++){
					for(int w=1;w<=3;w++){
						for(int e=1;e<=3;e++){
							if(j==q&&j==w){
								continue;
							}
							if(j==q&&j==e){
								continue;
							}
							if(j==w&&j==e){
								continue;
							}
							if(e==q&&e==w){
								continue;
							}
							if(a[1][j]+a[2][q]+a[3][w]+a[4][e]>ans){
								ans=a[1][j]+a[2][q]+a[3][w]+a[4][e];
							}
						}
					}
				}
			}
			cout<<ans<<endl; 
		}
		if(n==200){
			for(int j=1;j<=n;j++){
				if(a[j][1]>a[j][2]){
					ans+=a[j][1];
					y++;
					c[j]=a[j][1]-a[j][2];
				}else{
					ans+=a[j][2];
					u++;
					d[j]=a[j][2]-a[j][1];
		    	}
		    }
		    if(y>u){
		    	for(int j=1;j<y;j++){
				    for(int k=j+1;k<=y;k++){
						if(c[j]>c[k]){
							swap(c[j],c[k]);
						}
					}
				}
				for(int j=1;j<=y-u;j++){
					ans-=c[j];
				}
			}
			if(u>y){
		    	for(int j=1;j<u;j++){
				    for(int k=j+1;k<=u;k++){
						if(d[j]>d[k]){
							swap(d[j],d[k]);
						}
					}
				}
				for(int j=1;j<=u-y;j++){
					ans-=d[j];
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}

