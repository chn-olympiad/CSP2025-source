#include<bits/stdc++.h>
using namespace std;
//MUST DP.But I don't know how to do it. 
long long t,n,a[int(1e5)][3],c[3],maxn,maxc,good_sum;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(long long i=0;i<t;i++){
		good_sum=maxn=c[0]=c[1]=c[2]=0;
		cin>>n;
		for(long long j=0;j<n;j++){
			cin>>a[j][0]>>a[j][1]>>a[j][2];
			for(long long k=0;k<3;k++){
				if(a[j][k]>maxn){
					maxn=a[j][k];
					maxc=k;
				}
			}
			if(c[maxc]<n/2){
				good_sum+=maxn;
				c[maxc]++;
			}
			else{
				if(maxc==0){
					if(a[j][1]>a[j][2]){
						good_sum+=a[j][1];
						c[1]++;
					}
					else{
						good_sum+=a[j][2];
						c[2]++;
					}
				}
				else if(maxc==1){
					if(a[j][0]>a[j][2]){
						good_sum+=a[j][0];
						c[0]++;
					}
					else{
						good_sum+=a[j][2];
						c[2]++;
					}
				}
				else if(maxc==2){
					if(a[j][0]>a[j][1]){
						good_sum+=a[j][0];
						c[0]++;
					}
					else{
						good_sum+=a[j][1];
						c[1]++;
					}
				}
			}
		}
		cout<<good_sum<<endl;
	}
	return 0;
}
