#include<bits/stdc++.h>
using namespace std;
int t,n,a[100010][3],v[100010][3],w[3],xz[100010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int k=0;k<t;k++){
		cin>>n;
		for(int i=0;i<n;i++)for(int j=0;j<3;j++)cin>>a[i][j];
		for(int i=0;i<n;i++){
			if(a[i][0]>a[i][1]&&a[i][0]>a[i][1]){
				v[i][0]=0,w[0]++;
				if(a[i][1]>a[i][2])v[i][1]=1,v[i][2]=2;
				else v[i][1]=2;v[i][2]=1;
			}else if(a[i][1]>a[i][2]){
				v[i][0]=1,w[1]++;
				if(a[i][0]>a[i][2])v[i][1]=0,v[i][2]=2;
				else v[i][1]=2,v[i][2]=0;
			}else{
				v[i][0]=2,w[2]++;
				if(a[i][0]>a[i][1])v[i][1]=0,v[i][2]=1;
				else v[i][1]=1,v[i][2]=0;
			}
			v[i][3]=a[v[i][0]]-a[v[i][1]];
			v[i][4]=a[v[i][1]]-a[v[i][2]];
		}
		while(w[0]>n/2||w[1]>n/2||w[2]>n/2){
			if(w[0]>n/2){
				int minn=20010,h=-1;
				for(int i=0;i<n;i++)if(v[i][1]==0&&v[i][3]<minn)minn=v[i][3],h=i;
				v[i][1]xz[h]=v[h][1];
			}
		}
	}
	for(int i=0;i<t;i++)cout<<i*i/4%10*i;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
