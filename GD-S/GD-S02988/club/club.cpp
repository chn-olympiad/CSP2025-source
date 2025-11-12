#include<bits/stdc++.h>
using namespace std;
struct node{
	int s,id;
}c[100005];
int t,n,a[5][100005],b[5],d,id;
bool cmp(node x,node y){
	return x.s<y.s;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	cin>>t;
	while(t--&&cin>>n){
		b[1]=b[2]=b[3]=d=id=0;
		for(int i=1;i<=n;i++){
			cin>>a[1][i]>>a[2][i]>>a[3][i];
			if(a[1][i]>=a[2][i]&&a[1][i]>=a[3][i])d+=a[1][i],b[1]++;
			else if(a[2][i]>=a[1][i]&&a[2][i]>=a[3][i])d+=a[2][i],b[2]++;
			else d+=a[3][i],b[3]++;
		}
		if(b[1]>n/2){
			for(int i=1;i<=n;i++)if(a[1][i]>=a[2][i]&&a[1][i]>=a[3][i])c[++id].id=i,c[id].s=a[1][i]-max(a[2][i],a[3][i]);
			sort(c+1,c+id+1,cmp);
			for(int i=1;i<=b[1]-n/2;i++)d-=c[i].s;
		}
		else if(b[2]>n/2){
			for(int i=1;i<=n;i++)if(a[2][i]>=a[1][i]&&a[2][i]>=a[3][i])c[++id].id=i,c[id].s=a[2][i]-max(a[1][i],a[3][i]);
			sort(c+1,c+id+1,cmp);
			for(int i=1;i<=b[2]-n/2;i++)d-=c[i].s;
		}
		else if(b[3]>n/2){
			for(int i=1;i<=n;i++)if(a[3][i]>=a[2][i]&&a[3][i]>=a[1][i])c[++id].id=i,c[id].s=a[3][i]-max(a[2][i],a[1][i]);
			sort(c+1,c+id+1,cmp);
			for(int i=1;i<=b[3]-n/2;i++)d-=c[i].s;
		}
		cout<<d<<endl;
	}
	return 0;
} 
