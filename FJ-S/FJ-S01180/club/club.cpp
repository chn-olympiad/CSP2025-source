#include<bits/stdc++.h>
using namespace std;
int t;//测试的次数
long long ans[5];//answer
int n,nr,n_2;//      n:num of meb ;    n_2:n/2(wall)
long long meb1,meb2,meb3;//各组成员数 
long long meb[100000][3];//member
long long m[100000];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int p=1;p<=t;p++){
		meb1=0;
		meb2=0;
		meb3=0;
		cin>>n;
		nr=n;
		n_2=n/2;
		for(int o=1;o<=n;o++)cin>>meb[o-1][0]>>meb[o-1][1]>>meb[o-1][2];
		for(int o=1;o<=n;o++){
			m[o-1]=fabs(meb[o-1][1]-meb[o-1][0])+fabs(meb[o-1][0]-meb[o-1][2])+fabs(meb[o-1][1]-meb[o-1][2]);
		}
		for(int o=1;o<=n;o++){
			int mx=1;
			for(int l=2;l<=n;l++){
				if(m[l-1]>=m[mx-1])mx=l;
			}
			if(meb[mx-1][0]>=meb[mx-1][1]&&meb[mx-1][0]>=meb[mx-1][2]){
				if(meb1<n_2){
					meb1++;
					ans[p-1]+=meb[mx-1][0];
					m[mx-1]=-1;
				}else if(meb2<n_2){
					if(meb3>=n_2){
						meb2++;
					    ans[p-1]+=meb[mx-1][1];
					    m[mx-1]=-1;
					}else{
						if(meb[mx-1][1]>=meb[mx-1][2]){
							meb2++;
					        ans[p-1]+=meb[mx-1][1];
					        m[mx-1]=-1;
						}else{
							meb3++;
					        ans[p-1]+=meb[mx-1][2];
					        m[mx-1]=-1;
						}
					}
				}else{
					meb3++;
					ans[p-1]+=meb[mx-1][2];
					m[mx-1]=-1;
				}
			}else if(meb[mx-1][1]>=meb[mx-1][0]&&meb[mx-1][1]>=meb[mx-1][2]){
				if(meb2<n_2){
					meb2++;
					ans[p-1]+=meb[mx-1][1];
					m[mx-1]=-1;
				}else if(meb1<n_2){
					if(meb3>=n_2){
						meb1++;
					    ans[p-1]+=meb[mx-1][0];
					    m[mx-1]=-1;
					}else{
						if(meb[mx-1][0]>=meb[mx-1][2]){
							meb1++;
					        ans[p-1]+=meb[mx-1][0];
					        m[mx-1]=-1;
						}else{
							meb3++;
					        ans[p-1]+=meb[mx-1][2];
					        m[mx-1]=-1;
						}
					}
				}else{
					meb3++;
					ans[p-1]+=meb[mx-1][2];
					m[mx-1]=-1;
				}
			}else if(meb[mx-1][2]>=meb[mx-1][0]&&meb[mx-1][2]>=meb[mx-1][1]){
				if(meb3<n_2){
					meb3++;
					ans[p-1]+=meb[mx-1][2];
					m[mx-1]=-1;
				}else if(meb1<n_2){
					if(meb2>=n_2){
						meb1++;
					    ans[p-1]+=meb[mx-1][0];
					    m[mx-1]=-1;
					}else{
						if(meb[mx-1][0]>=meb[mx-1][1]){
							meb1++;
					        ans[p-1]+=meb[mx-1][0];
					        m[mx-1]=-1;
						}else{
							meb2++;
					        ans[p-1]+=meb[mx-1][1];
					        m[mx-1]=-1;
						}
					}
				}else{
					meb2++;
					ans[p-1]+=meb[mx-1][1];
					m[mx-1]=-1;
				}
			}
		}	
	}
	for(int i=1;i<=t;i++){
		cout<<ans[i-1];
		if(i!=t)cout<<endl;
	}
	return 0;
}
