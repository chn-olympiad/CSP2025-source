//GZ-S00494   毕节七星关东辰实验学校 韩智宸
#include<bits/stdc++.h>
using namespace std;
long long  t,n;
int main(){
	freopen("club1.in","r",stdin);
	freopen("club1.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		long long a[n][3];
		for(int l=0;l<n;l++){
			cin>>a[l][1]>>a[l][2]>>a[l][3]; 
		}
		long long q1=0,q2=0,q3=0,w=0,p1[n],p2[n],p3[n],u;
		for(int l=0;l<n;l++){
			if(a[l][1]>a[l][2]&&a[l][1]>a[l][3]){
				w+=a[l][1];
				q1++;
			}
			else if (a[l][2]>a[l][1]&&a[l][2]>a[l][3]){
				w+=a[l][2];
				q2++;
			}
			else {
				w+=a[l][3];
				q3++;
			}
		}
		if(q2>(n/2)){
			for(int l=0;l<n;l++){
				if(a[l][2]-a[l][1]<a[l][2]-a[l][3]&&q1<(n/2)){
					p2[l]=a[l][2]-a[l][1];
				}
				else {
					p2[l]=a[l][2]-a[l][3];
				}
			}
			for(int l=0;l<n;l++){
				for(int o=l+1;o<l;o++){
					if(p2[l]>p2[o]){
						u=p2[l];
						p2[l]=p2[o];
						p2[o]=u;
					}
				}
			}
			for(int l=0;l<q2-(n/2);l++){
				w-=p2[l];
			}
		}
		if(q1>(n/2)){
			for(int l=0;l<n;l++){
				if(a[l][1]-a[l][2]<a[l][1]-a[l][3]){
					p1[l]=a[l][1]-a[l][2];
				}
				else {
					p1[l]=a[l][1]-a[l][3];
				}
			}
			for(int l=0;l<n;l++){
				for(int o=l+1;o<l;o++){
					if(p1[l]>p1[o]){
						u=p2[l];
						p1[l]=p1[o];
						p1[o]=u;
					}
				}
			}
			for(int l=0;l<q1-(n/2);l++){
				w-=p1[l];
			}
		}
		if(q3>(n/2)){
			for(int l=0;l<n;l++){
				if(a[l][3]-a[l][1]<a[l][3]-a[l][2]&&q1<(n/2)){
					p3[l]=a[l][3]-a[l][1];
				}
				else {
					p3[l]=a[l][3]-a[l][2];
				}
			}
			for(int l=0;l<n;l++){
				for(int o=l+1;o<l;o++){
					if(p3[l]>p3[o]){
						u=p3[l];
						p3[l]=p3[o];
						p3[o]=u;
					}
				}
			}
			for(int l=0;l<q3-(n/2);l++){
				w-=p3[l];
			}
		}
	cout<<w<<endl;
	}
	return 0;
}

