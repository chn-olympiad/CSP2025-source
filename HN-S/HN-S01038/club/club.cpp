#include<bits/stdc++.h>
using namespace std;
long long a1[20010],a2[20010],a3[20010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long a,b,c,d,e,f,g,h,i,j,k;
	cin>>a;
	for(i=1;i<=a;i++){
		cin>>b;
		f=0;
		g=0;
		a1[0]=0;
		a2[0]=0;
		a3[0]=0;
		for(j=1;j<=b;j++){
			cin>>c>>d>>e;
			if(c>d&&c>e){
				a1[0]++;
				a1[c-max(d,e)]++;
				g=max(g,c-max(d,e));
			}else if(d>c&&d>e){
				a2[0]++;
				a2[d-max(c,e)]++;
				g=max(g,d-max(c,e));
			}else if(e>c&&e>d){
				a3[0]++;
				a3[e-max(c,d)]++;
				g=max(g,e-max(d,c));
			}
			f+=max(c,max(d,e));
		}
		b/=2;
		if(a1[0]>b){
			j=a1[0]-b;
			k=1;
			while(j>0){
				if(j>=a1[k]){
					f-=a1[k]*k;
					j-=a1[k];
				}else{
					f-=j*k;
					j=0;
				}
				k++;
			}
		}else if(a2[0]>b){
			j=a2[0]-b;
			k=1;
			while(j>0){
				if(j>=a2[k]){
					f-=a2[k]*k;
					j-=a2[k];
				}else{
					f-=j*k;
					j=0;
				}
				k++;
			}
		}else if(a3[0]>b){
			j=a3[0]-b;
			k=1;
			while(j>0){
				if(j>=a3[k]){
					f-=a3[k]*k;
					j-=a3[k];
				}else{
					f-=j*k;
					j=0;
				}
				k++;
			}
		}
		cout<<f<<'\n';
		for(j=1;j<=g;j++){
			a1[j]=0;
			a2[j]=0;
			a3[j]=0;
		}
	}
	return 0;
}
