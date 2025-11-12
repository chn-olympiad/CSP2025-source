#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][5],b[100005],c[100005];
long long s,sum;
int rest[5];
long long max(long long a,long long b){
	if(a>b){
		return a;
	}
	return b;
}

bool cmp(int a,int b){
	return a>b;
}

void dfs(int k){
	if(k>n){
		sum=max(s,sum);
		return;
	}
	for(int i=1;i<=3;i++){
		if(rest[i]>0){
			rest[i]--;
			s+=a[k][i];
			dfs(k+1);
			s-=a[k][i];
			rest[i]++;
		}
	}
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--){
		bool f23=1;
		sum=0;
		s=0;
		cin>>n;
		rest[1]=n/2;
		rest[2]=n/2;
		rest[3]=n/2;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
			if(a[i][2]!=0||a[i][3]!=0){
				f23=0;
			}
		}
		if(f23==0)
			dfs(1);
		else{
			for(int i=1;i<=n;i++){
				b[i]=a[i][1];
			}
			sort(b+1,b+1+n,cmp);
			for(int i=1;i<=n/2;i++){
				sum+=b[i];
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}

