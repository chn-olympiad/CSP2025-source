//GZ-S00327 贵州师范大学云岩实验中学 王永年 
#include<bits/stdc++.h>
using namespace std;
bool cmp(long long a,long long b) {
	return a>b;
}
int t;
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=0; i<t; i++) {
		long long ans=0;
		int n;
		cin>>n;
		int maxn=n/2;//单个部门最多人数
		long long wanna[n][3];//输入
		long long pira[n];
		long long pirb[n];
		long long pirc[n];
		long long allina[3*n];
		int yysan =0;
		for(int j=0; j<n; j++) {
			for(int z=0; z<3; z++) {
				cin>>wanna[j][z];
				allina[yysan]=wanna[j][z];
				yysan++;
				if(z==0) {
					pira[j]=wanna[j][0];
				}
				if(z==1) {
					pirb[j]=wanna[j][1];
				}
				if(z==2) {
					pirc[j]=wanna[j][2];
				}
			}
		}
		//	sort(focussort[0][0],focussort[0][0+n],cmp);
		sort(pira,pira+n,cmp);
		sort(pirb,pirb+n,cmp);
		sort(pirc,pirc+n,cmp);
		sort(allina,allina+(3*n),cmp);
		int u=0;//a
		int v=0;//b
		int w=0;//c
		//	long long pirzelss[3]={pira[0],pirb[0],pirc[0]};
		//	sort(pirzelss,pirzelss+3,cmp);
		//	for(int j=0;j<3;j++){
		//	if(pirzelss[j]==pira[0]){
		//	}
		//	}
		//	for(int j=0;j<n;j++){
		//		if(wanna[j][0]==pira[u]){
		//	wanna[j][0]=-1;
		//	wanna[j][1]=-1;
		//	wanna[j][2]=-1;
		//	ans+=pira[u];
		//	pira[u]=0;
		//	u++;
		//	}
		//	}
		for(int j=0; j<n*3; j++) {
			for(int z=0; z<n; z++) {
				if(u+v+w==n) {
					break;
				}
				if(pira[z]==allina[j]&&u<maxn) {
					for(int jk=0; jk<n; jk++) {
						if(wanna[jk][0]==allina[j]&&wanna[jk][0]>=0&&allina[j]>=0) {
							wanna[jk][0]=-1;
							wanna[jk][1]=-1;
							wanna[jk][2]=-1;
							ans+=allina[j];
							//cout<<ans<<endl;
							allina[j]=-1;
							u++;
						}
					}
				}
				if(pirb[z]==allina[j]&&v<maxn) {
					//cout<<v<<endl;
					for(int jk=0; jk<n; jk++) {
						if(wanna[jk][1]==allina[j]&&wanna[jk][1]>=0&&allina[j]>=0) {
							wanna[jk][0]=-1;
							wanna[jk][1]=-1;
							wanna[jk][2]=-1;
							v++;
							//if(v==maxn){
							//	break;
						//	}
							ans+=allina[j];
						//cout<<ans<<endl;
							allina[j]=-1;
								
						}
					}
				}
				if(pirc[z]==allina[j]&&w<maxn) {
					for(int jk=0; jk<n; jk++) {
						if(wanna[jk][2]==allina[j]&&wanna[jk][2]>=0&&allina[j]>=0) {
							wanna[jk][0]=-1;
							wanna[jk][1]=-1;
							wanna[jk][2]=-1;
							ans+=allina[j];
							//cout<<ans<<endl;
							allina[j]=-1;
							w++;
						}
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

