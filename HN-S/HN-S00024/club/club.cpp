#include<bits/stdc++.h>
#define ai3 array<int,3>
#define ll long long
using namespace std;
const int N=1e5+5;
int n,a[N][3];
int cnt[4],t[N];
void read(int &x){
	x=0;char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+(c^'0'),c=getchar();
}
void solve(){
	cnt[0]=cnt[1]=cnt[2]=0;
	read(n);
	int sum=0;
	for(int i=1;i<=n;i++){
		read(a[i][0]);
		read(a[i][1]);
		read(a[i][2]); 
		int id=0;
		for(int j=1;j<3;j++){
			if(a[i][j]>a[i][id])id=j;
		}
		t[i]=id;
		sum+=a[i][id];
		cnt[id]++;
	}
	bool f=false;
	int id=0;
	for(int i=0;i<3;i++){
		if(cnt[i]>n/2){
			f=true;
			id=i;
		}
	}
	if(!f){
		cout<<sum<<"\n";
		return;
	}
	vector<int>v;
	for(int i=1;i<=n;i++){
		if(t[i]==id){
			int mx=0;
			for(int j=0;j<3;j++){
				if(j!=id)mx=max(mx,a[i][j]);
			}
			v.push_back(a[i][id]-mx);
		}
	}
	sort(v.begin(),v.end());
	for(int i=0;i<cnt[id]-n/2;i++){
		sum-=v[i];
	}
	cout<<sum<<"\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	read(t);
	while(t--)solve();
	return 0;
} 
