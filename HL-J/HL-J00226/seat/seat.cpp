#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m;
	int n;
	cin>>n>>m;
	int hang[m]={0};
	int i=m*n;
	int map[n][m];
	int p[i]={0};
	int p1[i]={0};
	int b,k;
	int a1,a2,a3,a4,a5;
	for(int q=1;q<=m;q++){
		int w=m;
		hang[q]=w;
		w--;
	}
	for(int j=1;j<=i;j++){
		cin>>p[j];
		b=p[1];
	}
	for(int b=1;b<=i;b++){
		for(int a=1;a<=i;a++){
		if(p[a]<p[a+1]){
			int u;
			u=p[a];
			p[a]=p[a+1];
			p[a+1]=u;
		}
	}
}

	for(int h=1;h<=i;h++){
		if(p[h]==b){
			k=h;
		}
	}
	if(k%m==0){
		a1=k/m;
	}else{
		a1=k/m+1;
	}

		a3=k/n;
		a5=a3+1;
		a4=k%n;
		if(a4==0){
			if(a3%2==0){
				a2=1;
		}else{
				a2=n;
			}
		}if(a4!=0){
			if(a5%2==0){
				a2=hang[k-a3*n];
			}else{
				a2=k-a3*n;
			}
		}

	cout<<a1<<" "<<a2;
	return 0;
}
