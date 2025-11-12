#include<bits/stdc++.h>
using namespace std;
int t,n;
int per[3]={0},sum=0;
struct club{
	int a1,a2,a3;
};
int maxn(club x){
	int amax=x.a1;
	if(amax<x.a2){
		amax=x.a2;
	}else if(amax<x.a3){
		amax=x.a3;
	}else{
		return amax;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		club a[n];
		for(int i=1;i<=n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
		}
		per[1]=0;
		per[2]=0;
		per[3]=0;
		for(int i=1;i<=n;i++){
			cout<<maxn(a[i])<<"  ";
		}
		for(int i=1;i<=n;i++){
			if(per[1]>n/2){
				for(int j=1;j<=n;j++){
					a[j].a1=-1;
				}
			}else if(per[2]>n/2){
				for(int j=1;j<=n;j++){
					a[j].a2=-1;
				}
			}else if(per[3]>n/2){
				for(int j=1;j<=n;j++){
					a[j].a3=-1;
				}
			}else{
			    if(maxn(a[i])==a[i].a1){
			    	per[1]++;
			    }else if(maxn(a[i])==a[i].a2){
				    per[2]++;
			    }else if(maxn(a[i])==a[i].a3){
				    per[3]++;
			    }
			}
			sum+=maxn(a[i]);
		}
		cout<<endl<<sum<<endl<<endl;
		sum=0;
	}
	return 0;
}
//Ren5Jie4Di4Ling5%
