#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
long long T,n,a[N][4],y[4],jj[N],rr,oo,gg;
struct node{
	long long z,id;
}maxn[N];
struct edge{
	long long z,id;
}er[N];
int main(){
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			jj[i]=0;
			maxn[i].z=0;
			maxn[i].id=0;
			er[i].z=0;
			er[i].id=0;
		}
		for(int i=1;i<=3;i++){
			y[i]=0;
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)
				cin>>a[i][j];	
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				if(a[i][j]>maxn[i].z){
					maxn[i].z=a[i][j];
					maxn[i].id=j;
				}
			}
			for(int j=1;j<=3;j++){
				if(maxn[i].id==j){
					y[j]++;
				}
			}
			for(int j=1;j<=3;j++){
				if(j!=maxn[i].id&&a[i][j]>er[i].z){
					er[i].z=a[i][j];
					er[i].id=j;
					break;
				}
			}
	}
	if(n==1){
		cout<<0;
	}
	///else if(n==2){
		//if(maxn[1].id!=maxn[2].id){
	//		cout<<maxn[1].z+maxn[2].z;
	//	}
	//	else{
	//		cout<<max(maxn[1].z+er[2].z,maxn[2].z+er[1].z);
	//	}
//	}
	else{
		int h=0,f=0,py=0;
		for(int i=1;i<=n;i++){
			h+=maxn[i].z;
		}
		if(y[1]<=n/2&&y[3]<=n/2&&y[2]<=n/2){
			py=1;
			cout<<h<<endl;
		}	
		else{
			if(y[1]>n/2){
				f=1;
			}
			if(y[2]>n/2){
				f=2;
			}
			if(y[3]>n/2){
				f=3;
			}
			gg=y[f]-n/2;
			int p=0;
			for(int k=1;k<=n;k++){
				if(maxn[k].id==f){
					p++;
					jj[p]=maxn[k].z;
				}
			}
			rr=h;
			oo=0;
			sort(jj+1,jj+p+1);
			for(int i=1;i<=gg;i++){
				for(int k=1;k<=n;k++){
					if(maxn[k].z==jj[i]){
						h=h+er[k].z-maxn[k].z;
					//	cout<<h<<" "<<er[k].z<<" "<<maxn[k].z<<endl;
						break;
					}
				}
			}
			
			for(int i=1;i<=p;i++){
				if(rr+er[i].z-maxn[i].z>=h){
					rr=rr+er[i].z-maxn[i].z;
					oo++;
				}
			}
			if(oo==gg){
				cout<<rr<<endl;
			}
			else{
				for(int i=1;i<=gg-oo;i++){
				for(int k=1;k<=n;k++){
					if(maxn[k].z==jj[i]){
						h=h+er[k].z-maxn[k].z;
					//	cout<<h<<" "<<er[k].z<<" "<<maxn[k].z<<endl;
						break;
					}
				}
			}
			}
		}		
	//	cout<<y[1]<<" "<<y[2]<<" "<<y[3]<<" "<<h<<endl<<py<<endl;
		}
	}	
	return 0;
}

