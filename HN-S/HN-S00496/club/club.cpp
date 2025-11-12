#include<bits/stdc++.h>
using namespace std;

const int N=1e5+7;
int T,n;
int a[N],b[N],c[N];
long long k;
bool f=1;

void dfs(int x,long long y,int A,int B,int C){
	if(x==n+1){
		k=max(k,y);
		return;
	}
	if(A<n/2){
		dfs(x+1,y+a[x],A+1,B,C);
	}
	if(B<n/2){
		dfs(x+1,y+b[x],A,B+1,C);
	}
	if(C<n/2){
		dfs(x+1,y+c[x],A,B,C+1);
	}
	return;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		k=-1;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(b[i]!=0||c[i]!=0){
				f=0;
			}
		}
		if(f){
			k++;
			sort(a+1,a+1+n);
			for(int i=n/2+1;i<=n;i++){
				k+=a[i];
			}
			cout<<k<<endl;
			continue;
		}
		dfs(1,0,0,0,0);
		cout<<k<<endl;
	}
	return 0;
}
