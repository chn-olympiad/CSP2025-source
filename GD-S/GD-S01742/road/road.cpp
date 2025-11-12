#include<bits/stdc++.h>
using namespace std;
struct road{
	int a;
	int b;
	long long v;
};
bool tmp(road a,road b){
	return a.v<b.v;
}
road rd[1020005];
int bcj[10005];
int find_up(int i){
	if(bcj[i]==i){
		return i;
	}
	else{
		return bcj[i]=find_up(bcj[i]);
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	int a,b,v;
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>rd[i].a>>rd[i].b>>rd[i].v;
	}
	int x;
	int xx=m;
	for(int i=0;i<k;i++){
		cin>>x;
		for(int j=1;j<=n;j++){
			cin>>rd[xx].v;
			rd[xx].a=i+n+1;
			rd[xx].b=j;
			xx++;
		}
	}
	n+=k;
	for(int i=1;i<=n;i++){
		bcj[i]=i;
	}
	long long ans=0;
	sort(rd,rd+xx,tmp);
	int qy=n;
	for(int i=0;i<xx;i++){
		if(find_up(rd[i].a)!=find_up(rd[i].b)){
			bcj[find_up(rd[i].a)]=find_up(rd[i].b);
			qy--;
			ans+=rd[i].v;
		}
		if(qy==1){
			break;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
