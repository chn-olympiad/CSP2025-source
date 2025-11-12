#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n;
long long ans;
priority_queue<pair<int,int>> q[5];
struct s{
	int a1,a2,a3;
	int maxx,midx,minx;
	int u[5];
} a[N];
void solve(int x){
	if(q[a[x].maxx].size()==n/2){
		int y=q[a[x].maxx].top().second;
//		if(t==1) cout<<a[x].u[3]<<' '<<q[a[x].maxx].top().first<<' '<<a[x].u[2]<<endl;
		if(a[x].u[3]-q[a[x].maxx].top().first>a[x].u[2]){
//			if(t==1) cout<<'.';
			q[a[x].maxx].pop();
			q[a[x].maxx].push({a[x].u[3]-a[x].u[2],x});
			q[a[y].midx].push({0,y});
		}
		else{
			q[a[x].midx].push({0,x});
		}
	}
	else{
		q[a[x].maxx].push({a[x].u[3]-a[x].u[2],x});
	}
}
bool C(s u,s v){
	int a11=u.a1,a12=u.a2,a13=u.a3;
	int a21=v.a1,a22=v.a2,a23=v.a3;
	int maxx1=max(a11,max(a12,a13));
	int maxx2=max(a21,max(a22,a23));
	if(maxx1==maxx2){
		int maxxn1=(a11==maxx1?max(a12,a13):(a12==maxx1?max(a11,a13):max(a11,a12)));
		int maxxn2=(a21==maxx1?max(a22,a23):(a22==maxx1?max(a21,a23):max(a21,a22)));
		if(maxxn1==maxxn2){
			int n1=min(a11,min(a12,a13));
			int n2=min(a21,min(a22,a23));
			return n1>n2;
		}
		return maxxn1>maxxn2;
	}
	return maxx1>maxx2;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		priority_queue<pair<int,int>> q0;
		for(int i=1;i<=3;i++){
			q[i]=q0;
		}
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			if(a[i].a1>=a[i].a2&&a[i].a1>=a[i].a3) a[i].maxx=1;
			if(a[i].a2>=a[i].a1&&a[i].a2>=a[i].a3) a[i].maxx=2;
			if(a[i].a3>=a[i].a1&&a[i].a3>=a[i].a2) a[i].maxx=3;
			if(a[i].a3<=a[i].a1&&a[i].a3<=a[i].a2) a[i].minx=3;
			if(a[i].a2<=a[i].a1&&a[i].a2<=a[i].a3) a[i].minx=2;
			if(a[i].a1<=a[i].a2&&a[i].a1<=a[i].a3) a[i].minx=1;
			if(a[i].maxx==3&&a[i].minx==2) a[i].midx=1;
			if(a[i].maxx==1&&a[i].minx==3) a[i].midx=2;
			if(a[i].maxx==1&&a[i].minx==2) a[i].midx=3;
			if(a[i].maxx==2&&a[i].minx==3) a[i].midx=1;
			if(a[i].maxx==3&&a[i].minx==1) a[i].midx=2;
			if(a[i].maxx==2&&a[i].minx==1) a[i].midx=3;
			a[i].u[1]=a[i].a1,a[i].u[2]=a[i].a2,a[i].u[3]=a[i].a3;
//			cout<<"[]"<<a[i].u[1]<<' '<<a[i].u[2]<<' '<<a[i].u[3]<<endl;
			sort(a[i].u+1,a[i].u+4);
//			cout<<"()"<<a[i].maxx<<' '<<a[i].midx<<' '<<a[i].minx<<endl;
//			cout<<"{}"<<a[i].u[1]<<' '<<a[i].u[2]<<' '<<a[i].u[3]<<endl;
		}
		sort(a+1,a+n+1,C);
		for(int i=1;i<=n;i++){
			solve(i);
		}
		for(int i=1;i<=3;i++){
			while(q[i].size()){
				int x=q[i].top().second;
//				cout<<x<<' ';
				q[i].pop();
				if(i==1) ans+=a[x].a1;
				if(i==2) ans+=a[x].a2;
				if(i==3) ans+=a[x].a3;
			}
//			cout<<endl;
		}
		cout<<ans<<endl;
	} 
	return 0;
}

