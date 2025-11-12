#include<iostream>
using namespace std;
long long t,n,a,b,c,sum;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a>>b>>c;
			sum=sum+a+b+c;
		}
	}
	cout<<sum;
	return 0;
}
/*#include<bits/stdc++.h>
using namespace std;
long long t,n,c1[100000],c2[100000],c3[100000],best[1000000],club1,club2,club3,sum,d;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	cin>>t;
	for(int tt=1;tt<=t;tt++){
		sum=0;
		d=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>c1[i]>>c2[i]>>c3[i];
		}
		for(int i=1;i<=n;i++){
			club1=n/2;
			club2=n/2;
			club3=n/3;
			d=0;
			sum=0;
			best[1]=c1[i];
			best[2]=c2[i];
			best[3]=c3[i];
			sort(best+1,best+1+n);
			if(c1[i]==best[1]){
				sum+=c1[i];
				club1--;
			}
			if(c2[i]==best[1]){
				sum+=c2[i];
				club2--;
			}
			if(c3[i]==best[1]){
				sum+=c3[i];
				club3--;
			}
			for(int j=1;j<=n;j++){
				if(j!=i){
					best[1]=c1[j];
					best[2]=c2[j];
					best[3]=c3[j];
					sort(best+1,best+1+n);
					if(c1[j]==best[1]){
						if(club1==0){
							if(c2[j]==best[2]){
								if(club2==0){
									club3--;
									sum+=c3[j];
								}
							}
							else{
								club2--;
								sum+=c2[j];
							}
						}
						else{
							club2--;
							sum+=c2[j];
						}
					}
					if(c2[j]==best[1]){
						if(club2==0){
							if(c1[j]==best[2]){
								if(club1==0){
									club3--;
									sum+=c3[j];
								}
							}
							else{
								club1--;
								sum+=c1[j];
							}
						}
						else{
							club1--;
							sum+=c1[j];
						}						
					}
					if(c3[j]==best[1]){
						if(club3==0){
							if(c1[j]==best[2]){
								if(club1==0){
									club2--;
									sum+=c2[j];
								}
							}
							else{
								club1--;
								sum+=c1[j];
							}
						}
						else{
							club3--;
							sum+=c3[j];
						}						
					}
				}
			}
			if(d<sum){
				d=sum;
			}
		}
		cout<<d;
	}

	return 0;
}
*/
