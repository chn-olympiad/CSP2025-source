//#include<bits/stdc++.h>
//#include<iostream>
//#include<cstdio>
//#include<algorithm>
//using namespace std;
//const int N=1e5+10;
//int t,a1[N],a2[N],a3[N],maxn;
//long long sum=0;
//int main(){
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
//	cin>>t;
//	for(int i=1;i<=t;i++){
//		sum=0;
//		int n;
//		cin>>n;
//		for(int j=1;j<=n;j++){
//			maxn=-1e9;
//			cin>>a1[i]>>a2[i]>>a3[i];
//			maxn=max(a1[i],maxn);
//			maxn=max(a2[i],maxn);
//			maxn=max(a3[i],maxn);
//			sum+=maxn;
//		}
//		cout<<sum<<endl;
//	}
//	return 0;
//}
#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1e5+10;
const int M=10;
int t,a[M][N],maxn=-1e9,l[M],n,s;
long long sum;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int k=1;k<=t;k++){
		int cnt[M]={0,0,0,0,0,0,0,0,0,0};
		sum=0;
		cin>>n;
		s=n/2;
		for(int i=1;i<=n;i++){
			int l1,l2,l3;
			int maxn[M]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
			if(maxn[1]<a[i][1]){
				maxn[1]=a[i][1];
				if(maxn[1]<a[i][2]){
					maxn[1]=a[i][2];
					maxn[2]=a[i][1];
					if(maxn[1]<a[i][3]){
						maxn[1]=a[i][3];
						maxn[2]=a[i][2];
					}
					else{
						if(maxn[2]<a[i][3]){
							maxn[3]=maxn[2];
							maxn[2]=a[i][3];
						}
						else{
							maxn[3]=a[i][3];
						}
					}
				}
				else{
					maxn[2]=a[i][2];
					if(maxn[1]<a[i][3]){
						maxn[1]=a[i][3];
						maxn[2]=a[i][2];
					}
					else{
						if(maxn[2]<a[i][3]){
							maxn[3]=maxn[2];
							maxn[2]=a[i][3];
						}
						else{
							maxn[3]=a[i][3];
						}
					}
				}
			}
			if(cnt[1]>=s){
				if(cnt[2]>=s){
					sum+=maxn[3];
					cnt[3]++;
				}
				else{
					sum+=maxn[2];
					cnt[2]++;
				}
			}
			else{
				sum+=maxn[1];
				cnt[1]++;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
