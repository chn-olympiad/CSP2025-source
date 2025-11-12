#include<bits/stdc++.h>
using namespace std;
struct node{
	int val,id;
};
int t,n,a[100001],b[100001],c[100001],d[5],mx,fl2,fl3;
vector<node>v1,v2;
void dfs(int i,int points){
	if(i==n+1){
		if(d[1]<=n/2&&d[2]<=n/2&&d[3]<=n/2){
			mx=max(mx,points);
		}
	}
	dfs(i+1,points+a[i]);
	dfs(i+1,points+b[i]);
	dfs(i+1,points+c[i]);
}
bool cmp(node a,node b){
	return a.val<b.val;
}
bool cmp2(int a,int b){
	return a>b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		mx=-1;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(b[i]!=0){
				fl2=1;
			}
			if(c[i]!=0){
				fl3=1;
			}
		}
		if(n<=10){
			dfs(1,0);
			cout<<mx;
		}else{
			if(fl2==0&&fl3==0){//A
				sort(a+1,a+1+n,cmp2);
				for(int i=1;i<=n/2;i++){
					mx+=a[i];
				}
				cout<<mx;
			}else if(fl3==0){//B
				for(int i=1;i<=n;i++){
					if(a[i]>b[i]){
						d[1]++;
						mx+=a[i];
						v1.push_back({a[i],i});
					}else{
						d[2]++;
						mx+=b[i];
						v2.push_back({b[i],i});
					}
				}
				sort(v1.begin(),v1.end(),cmp);
				sort(v2.begin(),v2.end(),cmp);
				if(v1.size()>v2.size()){
					for(int i=v1.size()-1;i>=n/2;i--){
						mx-=v1[i].val;
						mx+=b[v1[i].id];
					}
				}
				cout<<mx;
			}else{
				cout<<0;
			}
		}
	}
	return 0;
}//witten by zsz0804_/GD-S00660 
/*  I use 1h to write the code below,
	and I want to baoli,
	although I can only get about 30 points.:(
	I'm a suger-bean.(O_O)(qwp)
#include<bits/stc++.h>
using namespace std;
const int N=1e5+1;
struct per{
	int a,b,c,d;
}p[N];
int t,n,b[5],cnt;
vector<int> vec,vec2;
int mxa(int i){
	if(p[i].a>p[i].b&&p[i].a>p[i].c)//a is the max
		return 1;
	else if(p[i].b>p[i].a&&p[i].b>p[i].c)//b is the max
		return 2;
	else if(p[i].c>p[i].a&&p[i].c>p[i].b)//c is the max
		return 3;
	else if(p[i].a==p[i].b&&p[i].a==p[i].c)//a=b=c
		return 0;
	else if(p[i].a==p[i].b&&p[i].a>p[i].c)//a=b>c
		return -1;
	else if(p[i].a==p[i].c&&p[i].a>p[i].b)//a=c>b
		return -2;
	else if(p[i].b==p[i].c&&p[i].b>p[i].a)//b=c>a
		return -3;
}
void sol(){
	if(mxa(x)==-1)
		if(b[1]<b[2])
			b[1]++,p[x].d=1;
		else
			b[2]++,p[x].d=2;
	else if(mxa(x)==-2)
		if(b[1]<b[3])
			b[1]++,p[x].d=1;
		else
			b[3]++,p[x].d=3; 
	else
		if(b[2]<b[3])
			b[2]++,p[x].d=2;
		else
			b[3]++,p[x].d=3;
}
int mni(){
	if(b[1]<b[2]&&b[1]<b[3]){
		return 1;
	}else if(b[2]<b[1]&&b[2]<b[3]){
		return 2;
	}else if(b[3]<b[1]&&b[3]<b[2]){
		return 3;
	}else if(b[1]==b[2]&&b[2]==b[3]){
		return 1;
	}else if()
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>p[i].a>>p[i].b>>p[i].c;
			if(mxa(i)>0){
				b[mxa(i)]++;
				p[i].d=mxa(i);
			}else if(mxa(i)<0){
				vec.push_back(i);
			}else{
				vec2.push_back(i);
			}
		}
		for(int i=0;i<vec.size();i++){
			int x=vec[i];
			sol();
		}
		for(int i=0;i<vec2.size();i++){
			p[i].d=mni();
			b[mni()]++;
		}
	}
	return 0;
}*/
