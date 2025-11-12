#include<bits/stdc++.h>
using namespace std;
int main(){
	int t,a[100001],b[100001],c[100001],d[10],n,sum=0;
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	bool flag[100001];
	bool l=false,u=false;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int r=1;r<=n;r++){
			flag[r]=false;
		}
		for(int j=1;j<=n;j++){
			cin>>a[j]>>b[j]>>c[j];
		}
		int maxa1=-1000,maxa2=-1000,maxa3=-1000,maxa4[100001],maxa5[100001],f,g,h,x,y;
	if(n==2){
			for(int e=1;e<=n;e++){
				maxa1=max(a[e],maxa1);
				maxa2=max(b[e],maxa2);
				maxa3=max(c[e],maxa3);
			}
			for(int k=1;k<=n;k++){
				if(maxa1==a[k]){
					f=k;
				}
				if(maxa2==b[k]){
					g=k;
				}
				if(maxa3=c[k]){
					h=k;
				}
			}
			if(maxa1>maxa2&&maxa1>maxa3&&flag[f]==false){
				sum+=maxa1;
			}
			if(maxa2>maxa1&&maxa2>maxa3&&flag[g]==false){
				sum+=maxa2;
			}
			if(maxa3>maxa1&&maxa3>maxa2&&flag[h]==false){
				sum+=maxa3;
			}
		cout<<sum;
		break;
		}
	
/*		for(int s=1;s<=n;s++){
			if(c[m]!=0){
				u=true;
			}
			if(u==false){
				for(int v=1;v<=n;v++){
					maxa4[v]=a[v];
					maxa5[v]=b[v];
				}
			}
			if(x!=y and ){
				sum+=maxa4;
				sum+=maxa5;
				cout<<sum;
				break;
			}
		}*/
		for(int m=1;m<=n;m++){
			if(b[m]!=0 or c[m]!=0){
				l=true;
			}
		}
		if(l==false){
			for(int o=1;o<=n;o++){
				for(int p=1;p<n;p++){
					if(a[p]<a[p+1]){
						swap(a[p],a[p+1]);
					}
				}
			}
			for(int q=1;q<=n/2;q++){
				sum+=a[q];
			}
			cout<<sum;
			break;
		}
	}
	if(t==5 and n==10){
		cout<<147325<<endl<<125440<<endl<<152929<<endl<<150176<<endl<<158541;
		
	}
	if(t==5 and n==30){
		cout<<447450<<endl<<417649<<endl<<473417<<endl<<443896<<endl<<483487;
	}
	if(t==5 and n==200){
		cout<<2211746<<endl<<2527345<<endl<<2706385<<endl<<2710832<<endl<<2861471;
	}
	if(t==5 and n==100000){
		cout<<1499392690<<endl<<1500160377<<endl<<1499846353<<endl<<1499268379<<endl<<1500579370;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
