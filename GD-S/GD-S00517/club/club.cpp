#include<bits/stdc++.h>
#define fo(i,x,y) for(int i=(x);i<=(y);i++)
using namespace std;
const int N=100010;
int a[N][3],b[N],c[N],d[N],e[N],n,s;
bool f[N];
bool cmp1(int x,int y){
	return a[x][0]-a[x][1]<a[y][0]-a[y][1];
}
bool cmp2(int x,int y){
	return a[x][0]-a[x][2]<a[y][0]-a[y][2];
}
bool cmp3(int x,int y){
	return a[x][1]-a[x][0]<a[y][1]-a[y][0];
}
bool cmp4(int x,int y){
	return a[x][1]-a[x][2]<a[y][1]-a[y][2];
}
bool cmp5(int x,int y){
	return a[x][2]-a[x][0]<a[y][2]-a[y][0];
}
bool cmp6(int x,int y){
	return a[x][2]-a[x][1]<a[y][2]-a[y][1];
}
void yx(int b[],function<bool(int,int)>cmp1,function<bool(int,int)>cmp2,int w,int u,int v,int &z){
	int t1=1,t2=1;
	fo(i,1,b[0])
		e[i]=b[i];
	sort(b+1,b+1+b[0],cmp1);
	sort(e+1,e+1+b[0],cmp2);
	while(b[0]>n>>1){
		while(t1<=b[0]&&f[b[t1]])
			t1++;
		while(t2<=b[0]&&f[e[t2]])
			t2++;
		const int x=a[b[t1]][w]-a[b[t1]][u],y=a[e[t2]][w]-a[e[t2]][v];
		if(t1<=b[0]&&z<n>>1&&x<y){
			s-=x;
			f[b[t1++]]=1;
			z++;
		}
		else{
			s-=y;
			f[e[t2++]]=1;
		}
		b[0]--;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int w;
	cin>>w;
	while(w--){
		cin>>n;
		s=b[0]=c[0]=d[0]=0;
		fo(i,1,n){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			const int x=max({a[i][0],a[i][1],a[i][2]});
			s+=x;
			if(a[i][0]==x)
				b[++b[0]]=i;
			else if(a[i][1]==x)
				c[++c[0]]=i;
			else
				d[++d[0]]=i;
			f[i]=0;
		}
		if(b[0]>n>>1)
			yx(b,cmp1,cmp2,0,1,2,c[0]);
		else if(c[0]>n>>1)
			yx(c,cmp3,cmp4,1,0,2,b[0]);
		else if(d[0]>n>>1)
			yx(d,cmp5,cmp6,2,0,1,b[0]);
		cout<<s<<endl;
	}
	return 0;
}
