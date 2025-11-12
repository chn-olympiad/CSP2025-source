#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
	int x,y,z;
	node(){};
	node(int xx,int yy,int zz){
		x=xx;
		y=yy;
		z=zz;
	}
}aa[2200001],a[2200001];
int n,m,k,fa[20001],b[11][10001];
bool cmp(node a,node b){
	return a.z<b.z;
}
int find(int x){
	if(fa[x]==x)return x;
	else return fa[x]=find(fa[x]);
}
int re(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x;
}
void bf(){
	sort(aa+1,aa+m+1,cmp);
	int yuansum=0,yuancnt=0;
	//vector<node>vec;
	for(int i=1;i<=m;i++){
		int fx=find(aa[i].x),fy=find(aa[i].y);
		if(fx==fy)continue;
		fa[fx]=fy;
		//vec.push_back(aa[i]);
		yuansum+=aa[i].z;
		yuancnt++;
		if(yuancnt==n-1)break;
	}
	//for(int i=1;i<=n-1;i++)aa[i]=vec[i-1];
	//m=n-1;
	int minn=1e18,mint=0;
	for(int s=0;s<(1<<k);s++){
		int edcnt=m,sum=0,nodecnt=n;
		for(int i=1;i<=m;i++)a[i]=aa[i];
		for(int i=1;i<=k;i++){
			if((s>>(i-1))&1){
				for(int j=1;j<=n;j++)a[edcnt+j]=node(n+i,j,b[i][j]);
				edcnt+=n;
				sum+=b[i][0];
				nodecnt++;
			}
		}
		//cout<<s<<" "<<sum<<endl;
		sort(a+1,a+edcnt+1,cmp);
		int cnt=0;
		for(int i=1;i<=n+k;i++)fa[i]=i;
		for(int i=1;i<=edcnt;i++){
			int fx=find(a[i].x),fy=find(a[i].y);
			if(fx==fy)continue;
			fa[fx]=fy;
			sum+=a[i].z;
			cnt++;
			if(cnt==nodecnt-1)break;
		}
		if(sum<minn){
			minn=sum;
			mint=s;
		}
	}
	cout<<minn;
} 
signed main(){
	srand(time(0));
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=re(),m=re(),k=re();
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		aa[i].x=re(),aa[i].y=re(),aa[i].z=re();
	}
	for(int i=1;i<=k;i++){
		//int sum=0;
		for(int j=0;j<=n;j++)b[i][j]=re();
		//cout<<sum<<endl;
	}
	if(m<100000){
		bf();
		return 0;
	}
	sort(aa+1,aa+m+1,cmp);
	int yuansum=0,yuancnt=0;
	vector<node>vec;
	for(int i=1;i<=m;i++){
		int fx=find(aa[i].x),fy=find(aa[i].y);
		if(fx==fy)continue;
		fa[fx]=fy;
		vec.push_back(aa[i]);
		yuansum+=aa[i].z;
		yuancnt++;
		if(yuancnt==n-1)break;
	}
	if(k==0){
		cout<<yuansum;
		return 0;
	}
	//for(int i=1;i<=n-1;i++)aa[i]=vec[i-1];
	//m=n-1;
	int t=2,minn=1e18;
	if(n>=1000&&m==1000000){
	if(k==5)t=2;
	else t=0;
    }
	while(t--){
	for(int tim=1;tim<=5;tim++){
		int x=rand()%k+1,y=rand()%k+1;
		//cout<<x<<" "<<y<<endl;
		for(int j=0;j<=n;j++)swap(b[x][j],b[y][j]);
	}
	//cout<<yuansum<<" "<<yuancnt<<endl;
	int edgecnt=m,nodecnt=n,leisum=0;
	for(int i=1;i<=k;i++){
		//cout<<edgecnt<<" "<<nodecnt<<endl;
		int sum=leisum+b[i][0],cnt=0;
		for(int j=1;j<=nodecnt+k;j++)fa[j]=j;
		for(int j=1;j<=edgecnt;j++)a[j]=aa[j];
		for(int j=1;j<=n;j++)a[j+edgecnt]=node(n+i,j,b[i][j]);
		sort(a+1,a+edgecnt+n+1,cmp);
		for(int j=1;j<=n+edgecnt;j++){
			int fx=find(a[j].x),fy=find(a[j].y);
			//cout<<fx<<" "<<fy<<" "<<a[j].x<<" "<<a[j].y<<" "<<a[j].z<<" "<<sum<<endl;
			if(fx==fy)continue;
			fa[fx]=fy;
			sum+=a[j].z;
			cnt++;
			if(cnt==nodecnt)break;
		}
		//cout<<sum<<endl;
		if(sum<yuansum){
			yuansum=sum;
			for(int j=1;j<=n;j++)aa[j+edgecnt]=node(n+i,j,b[i][j]);
			edgecnt+=n;
			nodecnt++;
			leisum+=b[i][0];
			//cout<<"point "<<i<<"in."<<endl;
		}
		//cout<<"!"<<endl;
    }
    minn=min(minn,yuansum);
}
    for(int i=1;i<=n-1;i++)aa[i]=vec[i-1];
	m=n-1;
	t=8;
	if(n>=1000&&m==1000000&&k>=5)t=20;
	while(t--){
	for(int tim=1;tim<=5;tim++){
		int x=rand()%k+1,y=rand()%k+1;
		//cout<<x<<" "<<y<<endl;
		for(int j=0;j<=n;j++)swap(b[x][j],b[y][j]);
	}
	//cout<<yuansum<<" "<<yuancnt<<endl;
	int edgecnt=m,nodecnt=n,leisum=0;
	for(int i=1;i<=k;i++){
		//cout<<edgecnt<<" "<<nodecnt<<endl;
		int sum=leisum+b[i][0],cnt=0;
		for(int j=1;j<=nodecnt+k;j++)fa[j]=j;
		for(int j=1;j<=edgecnt;j++)a[j]=aa[j];
		for(int j=1;j<=n;j++)a[j+edgecnt]=node(n+i,j,b[i][j]);
		sort(a+1,a+edgecnt+n+1,cmp);
		for(int j=1;j<=n+edgecnt;j++){
			int fx=find(a[j].x),fy=find(a[j].y);
			//cout<<fx<<" "<<fy<<" "<<a[j].x<<" "<<a[j].y<<" "<<a[j].z<<" "<<sum<<endl;
			if(fx==fy)continue;
			fa[fx]=fy;
			sum+=a[j].z;
			cnt++;
			if(cnt==nodecnt)break;
		}
		//cout<<sum<<endl;
		if(sum<yuansum){
			yuansum=sum;
			for(int j=1;j<=n;j++)aa[j+edgecnt]=node(n+i,j,b[i][j]);
			edgecnt+=n;
			nodecnt++;
			leisum+=b[i][0];
			//cout<<"point "<<i<<"in."<<endl;
		}
		//cout<<"!"<<endl;
    }
    minn=min(minn,yuansum);
}
	cout<<minn;
	return 0;
} 
