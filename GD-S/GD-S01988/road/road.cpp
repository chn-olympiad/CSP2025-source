#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y,v;
}a[1000005];
int num=0;
int n,m,k;
int aa[1000066];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(k==0){
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].v;
			aa[i]=a[i].v;
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){	
				if(aa[i]>aa[j]){
					int t=aa[i];
					aa[i]=aa[j];
					aa[j]=t;
				}
			}
		}
		for(int i=1;i<n;i++){
			num+=aa[i];
		}
		cout<<num;
	}else{
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
