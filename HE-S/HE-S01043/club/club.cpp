#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long t,p,n;
	cin>>t;
	long long boss[t+1]={};
	for(int l=1;l<=t;l++){
		cin>>n;
		long long a[n+1][4]={},s[4]={},maxx=-100;
		long long w[n+1][4]={};
		for(long long i=1;i<=n;i++){
			for(long long j=1;j<=3;j++){
			cin>>a[i][j];
			if(a[i][j]>maxx){
				maxx=a[i][j];
			}
	}
		if(a[i][1]==maxx){
			if(s[1]!=n/2){
				s[1]++;
				w[i][1]=1;
			}else{
				if(s[1]==n/2){
					long long umax=-1,H1,G1,GG1,bo,wh=10000;
					for(long long h1=1;h1<=i-1&&w[h1][1]==1;h1++){
						long long g1,gg1;												
						if(a[h1][3]>=a[h1][2]&&s[3]!=n/2){
							g1=3;
						}else{
							if(a[h1][3]<a[h1][2]&&s[2]!=n/2){
							g1=2;
						}
						}											
						if(a[i][3]>=a[i][2]&&s[3]!=n/2){
							gg1=3;
						}else{
							if(a[i][3]<a[i][2]&&s[2]!=n/2){
							gg1=2;
						}
						}										
						if(((a[i][1]+a[h1][g1])>=(a[h1][1]+a[i][gg1]))&&((a[i][1]+a[h1][g1])>=umax)&&(a[h1][1]<=wh)){
							umax=a[i][1]+a[h1][g1];
							wh=a[h1][1];
							H1=h1;
							G1=g1;
							GG1=gg1;
							bo=1;
						}else{
							if(((a[i][1]+a[h1][g1])<(a[h1][1]+a[i][gg1]))&&((a[h1][1]+a[i][gg1])>=umax)){
							umax=a[h1][1]+a[i][gg1];
							H1=h1;
							G1=g1;
							GG1=gg1;
							bo=0;
						}
					}
						}									
						if(bo==1){
							s[G1]++;
							w[i][1]=1;
							w[H1][G1]=1;
							w[H1][1]=0;
						}else{
							if(bo==0){
							s[GG1]++;
							w[i][GG1]=1;
						}
						}
					}
				}
			}else{
				if(a[i][2]==maxx){
			if(s[2]!=n/2){
				s[2]++;
				w[i][2]=1;
			}else{
				if(s[2]==n/2){
					long long umax=-1,H2,G2,GG2,bo,wh=10000;
					for(long long h2=1;h2<=i-1&&w[h2][2]==1;h2++){
						long long g2,gg2;						
						if(a[h2][3]>=a[h2][1]&&s[3]!=n/2){
							g2=3;
						}else{
							if(a[h2][3]<a[h2][1]&&s[1]!=n/2){
							g2=1;
						}
						}						
						if(a[i][3]>=a[i][1]&&s[3]!=n/2){
							gg2=3;
						}else{
							if(a[i][3]<a[i][1]&&s[1]!=n/2){
							gg2=1;
						}
						}						
						if(((a[i][2]+a[h2][g2])>=(a[h2][2]+a[i][gg2]))&&((a[i][2]+a[h2][g2])>=umax)&&(a[h2][2]<=wh)){
							umax=a[i][2]+a[h2][g2];
							wh=a[h2][2];
							H2=h2;
							G2=g2;
							GG2=gg2;
							bo=1;
						}else{
							if(((a[i][2]+a[h2][g2])<(a[h2][2]+a[i][gg2]))&&((a[h2][2]+a[i][gg2])>=umax)){
							umax=a[h2][2]+a[i][gg2];
							H2=h2;
							G2=g2;
							GG2=gg2;
							bo=0;
						}
					}
						}						
						if(bo==1){
							s[G2]++;
							w[i][2]=1;
							w[H2][G2]=1;
							w[H2][2]=0;
						}else{
							if(bo==0){
							s[GG2]++;
							w[i][GG2]=1;
						}
						}
					}
				}
			}else{
				if(a[i][3]==maxx){
			if(s[3]!=n/2){
				s[3]++;
				w[i][3]=1;
			}else{
				if(s[3]==n/2){
					long long umax=-1,H3,G3,GG3,bo,wh=10000;
					for(long long h3=1;h3<=i-1&&w[h3][3]==1;h3++){
						long long g3,gg3;						
						if(a[h3][2]>=a[h3][1]&&s[2]!=n/2){
							g3=2;
						}else{
							if(a[h3][2]<a[h3][1]&&s[1]!=n/2){
							g3=1;
						}
						}						
						if(a[i][2]>=a[i][1]&&s[2]!=n/2){
							gg3=2;
						}else{
							if(a[i][2]<a[i][1]&&s[1]!=n/2){
							gg3=1;
						}
						}						
						if(((a[i][3]+a[h3][g3])>=(a[h3][3]+a[i][gg3]))&&((a[i][3]+a[h3][g3])>=umax)&&(a[h3][3]<=wh)){
							umax=a[i][3]+a[h3][g3];
							wh=a[h3][3];
							H3=h3;
							G3=g3;
							GG3=gg3;
							bo=1;
						}else{
							if(((a[i][3]+a[h3][g3])<(a[h3][3]+a[i][gg3]))&&((a[h3][3]+a[i][gg3])>=umax)){
							umax=a[h3][3]+a[i][gg3];
							H3=h3;
							G3=g3;
							GG3=gg3;
							bo=0;
						}
					}
						}						
						if(bo==1){
							s[G3]++;
							w[i][3]=1;
							w[H3][G3]=1;
							w[H3][3]=0;
						}else{
							if(bo==0){
							s[GG3]++;
							w[i][GG3]=1;
						}
						}
					}
				}
			}
			}
			}
		maxx=-100;
		}
		for(long long e=1;e<=n;e++){
			for(long long o=1;o<=3;o++){
			if(w[e][o]==1){
				boss[l]+=a[e][o];
			}
		}
		}
	}
	for(long long ii=1;ii<=t;ii++){
		cout<<boss[ii]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
