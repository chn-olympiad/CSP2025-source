#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,m,k,ans=0,ans1=0,sum1=0,z[101],ans2=0,ans3=0;

struct e{
	int a,b,c,d;
}a[20000001]={0};

int f[10001];

bool cmp(e x,e y){
	return x.c<y.c;
}

int find(int x){
	if(f[x]==x){
		return x;
	}
	return find(f[x]);
}

void bin(int x,int y){
	f[find(x)]=find(y);
	
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i].a>>a[i].b>>a[i].c;
	}
	
	sort(a+1,a+m+1,cmp);
	
	for(int i=1;i<=k;i++){
		cin>>sum1;
		for(int j=1;j<=n;j++){
			cin>>z[j];
			if(z==0)ans3=j;
		}
		for(int j=1;j<=n;j++){
			if(ans3==j)continue;
			m++;
			a[m].a=ans3;
			a[m].b=j;
			a[m].c=z[j];
		}
	}
	
	for(int i=1;i<=m;i++){
		if(ans1==n-1)break;
		if(find(a[i].a)!=find(a[i].b)){
			ans1++;
			ans+=a[i].c;
			bin(a[i].a,a[i].b);
		}
	}
	cout<<ans;
	
	
}

/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/ 
