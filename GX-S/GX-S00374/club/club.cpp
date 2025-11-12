#include<bits/stdc++.h>
using namespace std;
int t,ans=0;
int n;
int per[4]={0};
struct man{
	int hap[4],in=0;
}p[100005];
bool allIn(){
	for(int i=1;i<=n;i++){
		if(p[i].in==0){
			return 0;
		}
	}
	return 1;
}
void bbs(int x[],int n,int m){
	for(int i=n;i<m;i++){
		for(int j=i;j<=m;j++){
			if(x[i]<x[j]){
				swap(x[i],x[j]);
			}
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		per[1]=0,per[2]=0,per[3]=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>p[i].hap[1]>>p[i].hap[2]>>p[i].hap[3];
		}
		int max=-1,maxin;
		for(int i=1;i<=3;i++){
			for(int j=1;i<=n;j++){
				if(!allIn()){
					if(per[i]>=n/2){
						break;
					}
					max=-1;
					for(int l=1;l<=3;l++){
						if(per[i]>=n/2){
							break;
						}
						for(int k=1;k<=n;k++){
							if(p[k].in==0){
								if(p[k].hap[l]>max){
									max=p[k].hap[l];
									maxin=k;
								}
							}
						}
					}
					per[i]++;
					p[maxin].in=1;
					ans+=max;
				}else{
					break;
				}
			}
		}
	}
	cout<<ans;
}
