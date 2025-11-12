#include<bits/stdc++.h>
using namespace std;

int t,tot=0;


int main(){
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		int n,maxn=0,tot=0;
		cin>>n;
		int a[n][3],maxx[n],maxc[n],num[3],minn=2e6+5,minc=0;
		int max2[n];
		 
		memset(maxx,0,sizeof(maxx));
		memset(num,0,sizeof(num));
		memset(max2,0,sizeof(max2));
		for(int j=0;j<n;j++){
			cin>>a[j][0]>>a[j][1]>>a[j][2];
			for(int q=0;q<3;q++){
				if(maxx[j]<=a[j][q]){
				max2[j]=a[j][q]-maxx[j];
					maxx[j]=a[j][q];
					maxc[j]=q;
				}
		}
		tot+=maxx[j];
		num[maxc[j]]++;
		for(int p=0;p<3;p++){
			while(num[p]>n/2){ //cout<<max2[0]<<endl;
				for(int e=0;e<n;e++){
						if(minn>=max2[e]){
							minn=max2[e];
						}
				}tot-=minn;
				num[p]--;
		}
		}
		}cout<<tot<<endl;
		
//		for(int j=0;j<3;j++){
//			if(num[j]>n/2){int minn[num[j]-q/2];
//				for(int q=0;q<num[j]-q/2;q++){
//					minn[q]=maxx[0];
//					for(int w=0;w<n;w++){
//						if(minn[q]>=maxx[w]){
//							minn[q]=maxc[w];
//						}
//					}
//					
//					
//				}
//			}
//		}
//	3
//	4
//	4 2 1
//	3 2 4
//	5 3 4
//	3 5 1
//4
//0 1 0
//0 1 0
//0 2 0
//0 2 0
//2
//10 9 8
//4 0 0

} return 0;
}
