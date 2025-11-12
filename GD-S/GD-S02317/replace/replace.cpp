#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct ac{
	int x,y,lx,ly,rx,ry;
}dis[200005];
ll n,m,sz[200005],II;
vector<string> sx,sy;
bool cmp(ac X,ac Y){
	return X.x-X.y<Y.x-Y.y;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	sx.push_back(""),sy.push_back("");
	for(int i=1;i<=n;i++){
		string xx,yy;
		cin>>xx>>yy;
		sx.push_back(xx);
		sy.push_back(yy);
		int nx=xx.size();
		sz[i]=nx;
		for(int j=1;j<=nx;j++){
			if(xx[j-1]=='b'){
				dis[i].x=j;
				dis[i].lx=j-1;
				dis[i].rx=n-j;
			}
			if(yy[j-1]=='b'){
				dis[i].y=j;
				dis[i].ly=j-1;
				dis[i].ry=n-j;
			}
		}
	}
//	cout<<"\n";
	sort(dis+1,dis+1+n,cmp);
	for(int i=1;i<=m;i++){
//		cout<<i<<"_"<<m<<"\n";
		string qx,qy;
		cin>>qx>>qy;
		int xx=qx.size(),yy=qy.size(),wherex,wherey,lX,rX,cnt=0;
		if(xx!=yy){
			cout<<0<<"\n";
			continue;
		}
		for(int j=1;j<=xx;j++){
			if(qx[j-1]=='b')wherex=j,lX=j-1,rX=xx-j;
			if(qy[j-1]=='b')wherey=j;
		}
		int cha=wherex-wherey;
//		cout<<wherex<<" "<<wherey<<"\n";
		int l=1,r=n,mid=(l+r)/2,pt=0;
		while(l<r){
			pt++;
			mid=(l+r)/2;
			if(dis[mid].x-dis[mid].y==cha)break;
			else if(dis[mid].x-dis[mid].y<cha)l=mid+1;
			else r=mid;
			if(pt==20)break;
		}
//		cout<<"mid:"<<mid<<" "<<dis[mid].x<<"-"<<dis[mid].y<<"="<<dis[mid].x-dis[mid].y<<"cmp"<<cha<<"\n";
		if(dis[mid].x-dis[mid].y!=cha){
			cout<<0<<"\n";
			continue;
		}
		l=mid,r=mid;
		while(dis[l].x-dis[l].y==cha)l--;
		while(dis[r].x-dis[r].y==cha)r++;
		if(dis[l].x-dis[l].y!=cha)l++;
		if(dis[r].x-dis[r].y!=cha)r--;
		for(int j=l;j<=r;j++){
			if(lX>=dis[j].lx&&rX>=dis[j].rx)cnt++;
		}
		cout<<cnt<<"\n";
	}
	return 0;
}
/*
3 2
aaba abaa
baa aab 
aba baa
baaa aaba
aaabaa aabaaa
*/
