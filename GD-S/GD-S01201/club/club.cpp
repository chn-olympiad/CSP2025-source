#include <bits/stdc++.h>
using namespace std;
const int N=2e5+6;
int t,n,a[N],b[N],c[N],minx=1000000,total=0,line[4],poo;
int check(){
	if(line[1]<=n/2 && line[2]<=n/2 && line[3]<=n/2)return 0;
	
	for(int i=1;i<=6;i++){
		if(line[i]>n/2){
			for(int j=1;j<=line[i]-n/2;j++){
				if(i%3==1){
					for(int f=1;f<=line[1];f++){
						minx=min(minx,a[f]);
						if(minx==a[f])poo=f;
					}
					total-=a[poo];
					line[i]--;
					if(b[i]>=c[i]){
						total+=b[i];
						line[2]++;
					}
					else{
						total+=c[i];
						line[3]++;
					}
				}
				if(i%3==2){
					for(int f=1;f<=line[2];f++){
						minx=min(minx,b[f]);
						if(minx==b[f])poo=f;
					}
					total-=b[poo];
					line[i]--;
					if(c[i]>=a[i]){
						total+=c[i];
						line[3]++;
					}
					else{
						total+=a[i];
						line[1]++;
					}
				}
				if(i%3==0){
					for(int f=1;f<=line[3];f++){
						minx=min(minx,c[f]);
						if(minx==c[f])poo=f;
					}
					total-=c[poo];
					line[i]--;
					if(a[i]>=b[i]){
						total+=a[i];
						line[1]++;
					}
					else{
						total+=b[i];
						line[2]++;
					}
				}
			}
		}
	}
	return 0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int q=1;q<=t;q++){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]>=b[i]){
				if(a[i]>=c[i]){
					total+=a[i];
					line[1]++;
				}
				else{
					total+=c[i];
					line[3]++;
				}
			}
			else{
				if(b[i]>=c[i]){
					total+=b[i];
					line[2]++;
					}
				else{
					total+=c[i];
					line[3]++;
				}
			}
		}
		check();
		cout<<total<<endl;
		total=0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
