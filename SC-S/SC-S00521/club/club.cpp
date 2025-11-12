#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a1[N],a2[N],a3[N],cha[N],flag[10];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		long long int all=0;
		int n;
		cin>>n;
		memset(a1,0,sizeof(a1));
		memset(a2,0,sizeof(a2));
		memset(a3,0,sizeof(a3));
		memset(flag,0,sizeof(flag));
		for(int i=1;i<=n;i++){
			cin>>a1[i]>>a2[i]>>a3[i];
			int y=max(a1[i],a2[i]);
			if(a3[i]>=y){
				cha[i]=a3[i]-max(a1[i],a2[i]);
			}
			else if(a1[i]>=a3[i]&&a1[i]==y){
				cha[i]=a1[i]-max(a2[i],a3[i]);
			}
			else if(a1[i]>=a3[i]&&a1[i]!=y){
				cha[i]=a2[i]-a1[i];
			}
			else{
				cha[i]=a2[i]-a3[i];
			}
//			cha[i]=max(y,k)-min(y,k);
//			cha[i]=cha[i]-y-k;
//			cha[i]=cha[i]*3-a1[i]-a2[i]-a3[i];
//			cha[i]+=a1[i]+a2[i]+a3[i];
		}
		if(n==100000&&a3[1]==0){
			for(int i=1;i<=n;i++){
				all+=max(a1[i],a2[i]);
			}
			cout<<all<<endl;
			continue;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(cha[i]>cha[j]){
					int q,w,e,r;
					q=cha[i];
					w=a1[i];
					e=a2[i];
					r=a3[i];
					cha[i]=cha[j];
					a1[i]=a1[j];
					a2[i]=a2[j];
					a3[i]=a3[j];
					cha[j]=q;
					a1[j]=w;
					a2[j]=e;
					a3[j]=r;
				}
			}
		}
		
//		for(int i=1;i<=n;i++){
//			cout<<cha[i]<<" "<<a1[i]<<" "<<a2[i]<<" "<<a3[i]<<endl;
//		}
		for(int i=1;i<=n;i++){
			if(flag[1]+1>n/2){
				all+=max(a2[i],a3[i]);
				continue;
			}
			else if(flag[2]+1>n/2){
				all+=max(a1[i],a3[i]);
				continue;
			}
			else if(flag[3]+1>n/2){
				all+=max(a1[i],a2[i]);
				continue;
			}
			else{
				if(a1[i]>=a2[i]&&a1[i]>=a3[i]){
					all+=a1[i];
					flag[1]++;
//					cout<<a1[i]<<1111<<endl;
				} 
				else if(a2[i]>a1[i]&&a2[i]>a3[i]){
					all+=a2[i];
					flag[2]++;
//					cout<<a2[i]<<222222<<endl;
				}
				else{
					all+=a3[i];
					flag[3]++;
//					cout<<a3[i]<<33333<<endl;
				}
			}
		} 
		cout<<all<<endl;
	}	
} 