#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][5],w1[100005],w2[100005],w3[100005],f1[100005],f2[100005],f3[100005],nn[4],c[100005],d=0;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
	cin >>n;
	nn[0]=0;nn[1]=0;nn[2]=0;nn[3]=0;d=0;
	for(int i=1;i<=n;i++){
		cin >> a[i][1]>>a[i][2]>>a[i][3];
		if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){w1[i]=1;if(a[i][2]>=a[i][3]){w2[i]=2;w3[i]=3;}else{w2[i]=3;w3[i]=2;}}
		else if(a[i][2]>a[i][1]&&a[i][2]>=a[i][3]){w1[i]=2;if(a[i][1]>=a[i][3]){w2[i]=1;w3[i]=3;}else{w2[i]=3;w3[i]=1;}}
		else{w1[i]=3;if(a[i][1]>=a[i][2]){w2[i]=1;w3[i]=2;}else{w2[i]=2;w3[i]=1;}}
		f1[i]=a[i][w1[i]];f2[i]=a[i][w2[i]];f3[i]=a[i][w3[i]];
		d+=f1[i];
	}for(int i=1;i<=n;i++){
		nn[w1[i]]++;
	}if(nn[1]>n/2){
		for(int i=1;i<=n;i++){
			c[i]=w1[i]==1?f1[i]-f2[i]:137891;
		}
		sort(c+1,c+n+1);
		for(int i=1;i<=nn[1]-n/2;i++){
			d-=c[i];
		}
	}else if(nn[2]>n/2){
		for(int i=1;i<=n;i++){
			c[i]=w1[i]==2?f1[i]-f2[i]:137891;
		}
		sort(c+1,c+n+1);
		for(int i=1;i<=nn[2]-n/2;i++){
			d-=c[i];
		}
	}else if(nn[3]>n/2){
		for(int i=1;i<=n;i++){
			c[i]=w1[i]==3?f1[i]-f2[i]:137891;
		}
		sort(c+1,c+n+1);
		for(int i=1;i<=nn[3]-n/2;i++){
			d-=c[i];
		}
	}cout<<d<<endl;
}}