#include<bits/stdc++.h>
using namespace std;
int a[10000],b[100000],c[10000];
int max=0;
int sum=0;
int suma=0;
int sumb=0;
int sumc=0;
int n[100000];
int x;
bool cmp(int f,int g){
	return f>g;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int l;
	cin>>l;
	int n;
	for(int i=1;i<=l;i++){
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a[j]>>b[j]>>c[j];
		}
	}
	for(int i=1;i<=l;i++){
		for(int j=1;j<=n;j++){
			x=n/2;
			if(a[j]>b[j]&&a[j]>c[j]){
				sum+=a[j];
				suma++;
			}else if(b[j]>a[j]&&b[j]>c[j]){
				sum+=b[j]; 
				sumb++;
			}else if(c[j]>a[j]&&c[j]>b[j]){
				sum+=c[j];
				sumc++;
			}
			if(suma>x){
				sort(a+1,a+n+1,cmp);
				for(int z=1;z<=x;z++){
					sum+=a[z];
				}	
			}
			if(sumb>x){
				sort(b+1,b+n+1,cmp);
				for(int z=1;z<=x;z++){
					sum+=b[z];
				}	
			}
			if(sumc>x){
				sort(c+1,c+n+1,cmp);
				for(int z=1;z<=x;z++){
					sum+=c[z];
				}	
			}
		}
		cout<<sum<<endl;
		sum=0;
		x=0;
		a[i]=0;
		b[i]=0;
		c[i]=0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
