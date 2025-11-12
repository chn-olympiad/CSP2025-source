#include<bits/stdc++.h>
using namespace std;

const int N=1000;
const int R=998244353;
int a[N+10];

int jl[N+10];
bool hah[N+10]={0};
long long res=0;
long long tmp=0;
int m=0;
int ans;

void print(int z){
	if(ans==1){
		res++;
		res%=R;
		return;
	}
	
	tmp=0;
	m=0;
	for(int i=1; i<=z; i++){
		tmp+=jl[i];
		m=max(m,jl[i]);
	}
	if(tmp>m*2){
		res++;
		res%=R;
	}
}

int n;

void dfs(int k,int z,int s){
	for(int i=s+1; i<=n; i++){
		if(hah[i]==0){
			hah[i]=1;
			jl[k]=a[i];
			
			if(k==z){
				print(z);
			}else{
				dfs(k+1,z,i);
			}
			
			hah[i]=0;
			jl[k]=0;
		}
	}
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);

	
	cin>>n;
	
	ans=1;
	for(int i=1; i<=n; i++){
		cin>>a[i];
		ans=max(a[i],ans);
	}

	if(n<=3){
		if(n<3) cout<<0;
		if(a[1]+a[2]+a[3]>ans*2) cout<<1;
		else cout<<0;
	}else{
		long long sum=0;
		for(int i=3; i<=n; i++){
			res=0;
			dfs(1,i,0);
			sum+=res;
			sum%=R;
		}
		cout<<sum;
	}

	return 0;
}
