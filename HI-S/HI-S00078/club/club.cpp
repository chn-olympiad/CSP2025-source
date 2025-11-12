#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int p[N][3],sp1[N],sp2[N],sp3[N];
int n,t;
void pfo(){
	int pp[3],ppp[3];
	for(int j=1;j<=3;j++){
		cin>>pp[j];
	}
	for(int j=1;j<=3;j++){
		cin>>ppp[j];
	}
	for(int i=1;i<=2;i++){
		if(pp[i]>pp[i+1]){
			int yu=pp[i];
			pp[i]=pp[i+1];
			pp[i+1]=yu;
		}
	}
	for(int i=1;i<=2;i++){
		if(ppp[i]>ppp[i+1]){
			int yu=ppp[i];
			ppp[i]=ppp[i+1];
			ppp[i+1]=yu;
		}
	}
	for(int j=1;j<=3;j++){
		cout<<pp[j]<<" ";
	}
	for(int j=1;j<=3;j++){
		cout<<ppp[j]<<" ";
	}
	cout<<pp[3]+ppp[3]<<endl;
	return;
}
void ins(){
	for(int i=2;i<=t;i++){
		for(int j=1;j<=3;j++){
			cin>>p[i][j];
		}
		sp1[i]=p[i][1];
		sp2[i]=p[i][2];
		sp3[i]=p[i][3];
	}
}
void pft(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-1;j++){
			if(sp1[j]>sp1[j+1]){
				int yu=sp1[j];
				sp1[j]=sp1[j+1];
				sp1[j+1]=yu;
			}
		}
	}
	int pou=0;
	for(int i=n;i>=n/2+1;i--){
		cout<<sp1[i]<<" ";
		pou+=sp1[i];
	}
	cout<<pou;
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t>>n;
	if(n==2){
		for(int i=1;i<=t;i++){
			pfo();
		}
		return 0;
	}
	for(int u=1;u<=t;u++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>p[i][j];
			}
			sp1[i]=p[i][1];
			sp2[i]=p[i][2];
			sp3[i]=p[i][3];
		}
		int all=0,all2=0;;
		for(int i=1;i<=n;i++){
			all+=sp2[i];
			all2+=sp3[i];
		}
		if(all==all2 and all==0){
			for(int i=1;i<=t;i++){
				if(i!=1){
					ins();
				}
				pft();
			}
			return 0;
		}
		sort(sp1,sp1+n);
		sort(sp2,sp2+n);
		sort(sp3,sp3+n);
		int sh1,sh2,sh3;
		int kk[N];
		int sum=0;
		int kj=0;
		int su[5]={0};
		for(int k=1;k<=3;k++){
			sum=0;
			for(int i=1;i<=n/2;i++){
				for(int j=n;j>=n-i;j++){
					if(k==1){
						sum+=sp1[j];
					}else if(k==2){
						sum+=sp2[j];
					}else if(k==3){
						sum+=sp3[j];
					}
				}
			}
			if(k==1){
				sum+=sp1[k];
			}else if(k==2){
				sum+=sp2[k];
			}else if(k==3){
				sum+=sp3[k];
			}
			su[k]=sum;
		}
		sort(su,su+3);
		cout<<su[3]<<endl;
	}
	return 0;
}
