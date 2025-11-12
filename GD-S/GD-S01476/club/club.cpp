#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;



long long t,n,ans,s[3],c[3][100086];
struct node{
	long long h[3],p[3];
}a[1000086];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	long long i,j,k;
	while(t>0){
		t--;
		for(i=0;i<=2;i++){
			c[i][0]=0;
			s[i]=0;
		}
		ans=0;
		cin>>n;
		for(i=1;i<=n;i++){
			cin>>a[i].h[0]>>a[i].h[1]>>a[i].h[2];
			if(a[i].h[0]>=a[i].h[1]){
				if(a[i].h[0]>=a[i].h[2]){
					a[i].p[0]=0;
					if(a[i].h[1]>=a[i].h[2]){
						a[i].p[1]=1;
						a[i].p[2]=2;
					}
					else{
						a[i].p[2]=1;
						a[i].p[1]=2;
					}
				}
				else{
					a[i].p[2]=1;
					a[i].p[1]=0;
					a[i].p[0]=2;
				}
			}
			else{
				if(a[i].h[1]>=a[i].h[2]){
					a[i].p[0]=1;
					if(a[i].h[0]>=a[i].h[2]){
						a[i].p[1]=0;
						a[i].p[2]=2;
					}
					else{
						a[i].p[2]=0;
						a[i].p[1]=2;
					}
				}
				else{
					a[i].p[0]=2;
					a[i].p[1]=1;
					a[i].p[2]=0;
				}
			}
			j=a[i].p[0];
			ans+=a[i].h[j];
			s[j]++;
			c[j][s[j]]=a[i].h[j]-a[i].h[a[i].p[1]];
			k=s[j];
			while(k>1){
				if(c[j][k]<c[j][k-1]){
					swap(c[j][k],c[j][k-1]);
					k--;
				}
				else k=0;
			}
		}
		/*cout<<ans<<"\n";*/
		for(i=0;i<=2;i++){
			if(s[i]>n/2){
				j=s[i]-n/2;
				for(;j>=1;j--) ans-=c[i][j];
				break;
			}
		}
		/*
		for(j=0;j<=2;j++) cout<<s[j]<<" "<<c[j][1]<<"\n";
		*/
		cout<<ans<<"\n";
	}	
	return 0;
}
