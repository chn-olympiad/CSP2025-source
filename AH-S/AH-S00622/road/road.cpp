#include <bits/stdc++.h>
using namespace std;
long long n,m,k,a[10010],b[10010],c[10010],t[12][10010],mx,mi,mi1,mi2,mi3,num;
bool l[10010];
bool l2[12];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	l[1]=1;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i]>>b[i]>>c[i];
	}
	for(int i=1;i<=k;i++){
		cin>>t[i][0];
		for(int j=1;j<=n;j++){
			cin>>t[i][j];
		}
	}
	mx=INT_MAX;
	for(int i=0;i<n-1;i++){
		for(int j=1;j<=m;j++){
			if(l[a[j]]!=l[b[j]]){
				mx=c[j];
				mi=j;
				mi1=j;
			}
		}
		mi2=a[mi1];
		mi3=b[mi1];
		if(l[mi3])
			swap(mi2,mi3);
		for(int j=1;j<=k;j++){
			for(int ta=1;ta<=n;ta++){
				if(!l[ta]&&(!l2[j])*t[j][0]+t[j][mi2]+t[j][ta]<mx){
					mx=(!l2[j])*t[j][0]+t[j][mi2]+t[j][ta];
					mi3=ta;
					mi=m+j;
				}
			}
		}
		if(mi<=m){
			num+=c[mi1];
			l[mi3]=1;
		}else{
			num+=t[mi-m][0]+t[mi-m][mi2]+t[mi-m][mi3];
			l[mi2]=l[mi3]=1;
			t[mi-m][0]=t[mi-m][mi2]=t[mi-m][mi3]=0;
		}
	}
	cout<<num;
	return 0;
}
