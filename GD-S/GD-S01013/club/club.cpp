#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct mem{
	long long x,y,z;
}a[N];
int T;
int n;
vector<int> pr1,pr2,pr3;
long long ans;
void init(){
	cin>>n;
	ans=0;
	pr1.clear();pr2.clear();pr3.clear();
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y>>a[i].z;
	}
}
void check(){
	if(pr1.size()>n/2){
		sort(pr1.begin(),pr1.end(),[&](int A,int B){return (a[A].x-max(a[A].y,a[A].z) > a[B].x-max(a[B].y,a[B].z)) ;});
		int i=0,sub=0;
		for(i=pr1.size()-1;i+1>n/2;i--){
			sub=pr1[i];
			if(a[sub].y>a[sub].z)
				ans=ans-a[sub].x+a[sub].y;
			else
				ans=ans-a[sub].y+a[sub].x;
		}
	}
}
void solve(){
	for(int i=1;i<=n;i++){
		ans+=max(a[i].x,max(a[i].y,a[i].z));
		if(a[i].x>max(a[i].y,a[i].z))
			pr1.push_back(i);
		else if(a[i].y>max(a[i].x,a[i].z))
			pr2.push_back(i);
		else
			pr3.push_back(i);
	}
	if(pr1.size()>n/2){
		sort(pr1.begin(),pr1.end(),[&](int A,int B){return (a[A].x-max(a[A].y,a[A].z) > a[B].x-max(a[B].y,a[B].z)) ;});
		int i=0,sub=0;
		for(i=pr1.size()-1;i+1>n/2;i--){
			sub=pr1[i];
			if(a[sub].y>a[sub].z)
				ans=ans-a[sub].x+a[sub].y;
			else
				ans=ans-a[sub].x+a[sub].z;
		}
	}
	else{
		if(pr2.size()>n/2){
			sort(pr2.begin(),pr2.end(),[&](int A,int B){return (a[A].y-max(a[A].x,a[A].z) > a[B].y-max(a[B].x,a[B].z)) ;});
			int i=0,sub=0;
			for(i=pr2.size()-1;i+1>n/2;i--){
				sub=pr2[i];
				if(a[sub].x>a[sub].z)
					ans=ans-a[sub].y+a[sub].x;
				else
					ans=ans-a[sub].y+a[sub].z;
			}
		}
		else if(pr3.size()>n/2){
			sort(pr3.begin(),pr3.end(),[&](int A,int B){return (a[A].z-max(a[A].x,a[A].y) > a[B].z-max(a[B].x,a[B].y)) ;});
			int i=0,sub=0;
			for(i=pr3.size()-1;i+1>n/2;i--){
				sub=pr3[i];
				if(a[sub].x>a[sub].y)
					ans=ans-a[sub].z+a[sub].x;
				else
					ans=ans-a[sub].z+a[sub].y;
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	for(;T--;){
		init();
		solve();
		cout<<ans<<'\n';
	}
	return 0;
} 
/*
15:04
*/
