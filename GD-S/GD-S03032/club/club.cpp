#include<bits/stdc++.h>
using namespace std;
int t,n,ans,maxn,minn;
int a[100100][5];
int b[50050];
int d1,d2,d3;
bool s1[100100],s2[100100],s3[100100];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t>=1){
		ans=0;
		d1=0;
		d2=0;
		d3=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		} 
		for(int i=1;i<=n;i++){
			maxn=max(a[i][1],a[i][2]);
			maxn=max(maxn,a[i][3]);
			if(maxn==a[i][1]){
				d1++;
				s1[i]=1;
				s2[i]=0;
				s3[i]=0;
			} else if(maxn==a[i][2]){
				d2++;
				s1[i]=0;
				s2[i]=1;
				s3[i]=0;
			} else{
				d3++;
				s1[i]=0;
				s2[i]=0;
				s3[i]=1;
			}
			//cout<<maxn<<"$"<<endl;
			ans+=maxn;
		}
		if(d1>n/2){
			for(int j=1;j<=n;j++){
				minn=min(a[j][1]-a[j][2],a[j][1]-a[j][3]);
				if(s1[j]=1){
					b[j]=minn;
				} else{
					b[j]=200200;
				}
			}
			sort(b+1,b+1+n);
			for(int j=1;j<=d1-(n/2);j++){
				ans-=b[j];
			}
		} else if(d2>n/2){
			for(int j=1;j<=n;j++){
				minn=min(a[j][2]-a[j][1],a[j][2]-a[j][3]);
				if(s2[j]=1){
					b[j]=minn;
				} else{
					b[j]=200200;
				}
			}
			sort(b+1,b+1+n);
			for(int j=1;j<=d2-(n/2);j++){
				ans-=b[j];
			}
		} else if(d3>n/2){
			for(int j=1;j<=n;j++){
				minn=min(a[j][3]-a[j][2],a[j][3]-a[j][1]);
				if(s3[j]=1){
					b[j]=minn;
				} else{
					b[j]=200200;
				}
			}
			sort(b+1,b+1+n);
			for(int j=1;j<=d3-(n/2);j++){
				ans-=b[j];
			}
		}
		cout<<ans<<endl;
		//cout<<d1<<" "<<d2<<" "<<d3<<endl;
		t--;
	}
	return 0;
}
