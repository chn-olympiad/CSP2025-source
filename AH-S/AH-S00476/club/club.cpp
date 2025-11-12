#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	long long n;
	
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		int w=0,tr=0,w2=0;
		int a[2100],b[210],c[2100],d[6300];
		for(int j=1;j<=n;j++){
			cin>>a[j]>>b[j]>>c[j];
			if(b[j]!=0&&c[j]!=0) tr=1;
			d[j*3-2]=a[j];
			d[j*3-1]=b[j];
			d[j*3]=c[j];
		}
		sort(d+1,d+n*3+1);
		for(int j=n*3;j>n*2;j--){
			w+=d[j];
		}
		if(tr==0){
			for(int j=n*3;j>n*3-n/2;j--){
				w2+=d[j];
			}
			cout<<w2;
		}
		else cout<<w;
		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
