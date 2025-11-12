#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5;
int t,n,cnt[5];
ll sum;
struct node{
	int x,y,z;
	int c,d,cd;
}a[N];
void solve(int i){
	int x=a[i].x;
	int y=a[i].y;
	int z=a[i].z;
	if(x>y){
		if(y>z){
			a[i].c=x-y;
			a[i].d=1,a[i].cd=2;
		}else{
			//y<x,y<z
			if(x>z){
				a[i].c=x-z;
				a[i].d=1,a[i].cd=3;
			}else{
				//y<x,x<z
				a[i].c=z-x;
				a[i].d=3,a[i].cd=1;
			}
		}
	}else{
		//x<y
		if(x>z){
			a[i].c=y-x;
			a[i].d=2,a[i].cd=1;
		}else{
			//x<y,x<z
			if(y>z){
				a[i].c=y-z;
				a[i].d=2,a[i].cd=3;
			}else{
				//x<y,y<z
				a[i].c=z-y;
				a[i].d=3,a[i].cd=2;
			}
		}
	} 
}
void work(int i){
	if(a[i].d==1){
		if(cnt[1]==n/2){
			if(a[i].cd==2){
				cnt[2]++;
				sum+=a[i].y;
			}else{
				cnt[3]++;
				sum+=a[i].z;
			}
		}else{
			cnt[1]++;
			sum+=a[i].x;
		}
	}else if(a[i].d==2){
		if(cnt[2]==n/2){
			if(a[i].cd==1){
				cnt[1]++;
				sum+=a[i].x;
			}else{
				cnt[3]++;
				sum+=a[i].z;
			}
		}else{
			cnt[2]++;
			sum+=a[i].y;
		}
	}else{
		if(cnt[3]==n/2){
			if(a[i].cd==1){
				cnt[1]++;
				sum+=a[i].x;
			}else{
				cnt[2]++;
				sum+=a[i].y;
			}
		}else{
			cnt[3]++;
			sum+=a[i].z;
		}
	}
}
bool cmp(node u,node v){
	return u.c>v.c;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		sum=0;
		for(int i=1;i<=3;i++) cnt[i]=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			solve(i);
		}
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n;i++){
			work(i);
		}
		cout<<sum<<"\n";
	}
	return 0;
}
