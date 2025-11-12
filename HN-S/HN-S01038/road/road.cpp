#include<bits/stdc++.h>
using namespace std;
long long a1[10010],a3[20][10010],a4[1010][1010],a5[1010][1010],a6,a7,a8[20];
struct t1{
	long long i,j,k;
}a2[2000010],a9[2000010];
bool s1(t1 a,t1 b){
	return a.k<b.k;
}
long long s2(long long a){
	if(a1[a]!=a){
		a1[a]=s2(a1[a]);
	}
	return a1[a];
}
long long s3(long long a){
	long long i=s2(a2[a].i),j=s2(a2[a].j);
	if(i==j){
		return 0;
	}
	a1[i]=a1[j]=min(i,j);
	return 1;
}
long long s4(long long a,long long b){
	long long g,h=0,i,j,k;
	if(a>a6){
		if(b==0){
			return 1000000000000000000;
		}
		for(i=1;i<=a7;i++){
			a1[i]=i;
		}
		for(i=1;i<=a8[0];i++){
			for(j=2;j<=a7;j++){
				for(k=1;k<j;k++){
					if(i==1){
						a5[k][j]=min(a4[k][j],a3[a8[i]][j]+a3[a8[i]][k]);
					}else{
						a5[k][j]=min(a5[k][j],a3[a8[i]][j]+a3[a8[i]][k]);
					}
				}
			}
		}
		k=0;
		for(i=2;i<=a7;i++){
			for(j=1;j<i;j++){
				k++;
				a2[k].i=i;
				a2[k].j=j;
				a2[k].k=a5[j][i];
			}
		}
		sort(a2+1,a2+1+k,s1);
		j=1;
		for(i=1;i<=k;i++){
			g=s3(i);
			j+=g;
			h+=g*a2[i].k;
			if(j==a7){
				return h;
			}
		}
	}
	a8[0]++;
	a8[a8[0]]=a;
	j=s4(a+1,b+1)+a3[a][0];
	a8[0]--;
	return min(j,s4(a+1,b));
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long a,b,c,d,e,f,g,h,i,j,k;
	cin>>a7>>b>>a6;
	for(i=1;i<=a7;i++){
		a1[i]=i;
	}
	for(i=1;i<=b;i++){
		cin>>a2[i].i>>a2[i].j>>a2[i].k;
	}
	for(i=1;i<=a6;i++){
		cin>>a3[i][0];
		for(j=1;j<=a7;j++){
			cin>>a3[i][j];
		}
	}
	sort(a2+1,a2+1+b,s1);
	d=1;
	e=0;
	for(i=1;i<=b;i++){
		f=s3(i);
		d+=f;
		e+=f*a2[i].k;
		if(d==a7){
			break;
		}
	}
	if(a6!=0){
		for(i=1;i<=a7;i++){
			for(j=1;j<=a7;j++){
				a4[i][j]=1000000000000000000;
			}
		}
		for(i=1;i<=b;i++){
			a4[min(a2[i].i,a2[i].j)][max(a2[i].i,a2[i].j)]=min(a4[min(a2[i].i,a2[i].j)][max(a2[i].i,a2[i].j)],a2[i].k);
		}
		e=min(e,s4(1,0));
	}
	cout<<e;
	return 0;
}
