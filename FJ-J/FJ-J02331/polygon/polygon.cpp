#include<bits/stdc++.h>
using namespace std;
const int N=5005,MOD=998244353;
int n,a[N],maxa,res,m[N],s[N];
void dfs(int l,vector<int> v){
	if(l<=n){
		s[l]=s[l-1]+a[v[v.size()-1]];
		m[l]=max(m[l-1],a[v[v.size()-1]]);
		if(l>=3){
			int maxn=m[l],sum=s[l];
//			int maxn=INT_MIN,sum=0;	
//			for(int j:v){
//				maxn=max(maxn,a[j]);
//				sum+=a[j];
//			}
			if(sum>2*maxn){
//				for(int j:v){
//					cout<<j<<" ";
//				}cout<<endl;
				res++;
				res%=MOD;
			}
		}
		v.push_back(0);
		for(int i=v[v.size()-2]+1;i<=n;i++){
			v[v.size()-1]=i;
			dfs(l+1,v);
		}
		s[l]=0;m[l]=0;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n==3){
		//1 to 3
		int a,b,c;
		cin>>a>>b>>c;
		cout<<(a+b>c&&a+c>b&&b+c>a&&a-b<c&&b-c<a&&a-c<b);
	}else{
		for(int i=1;i<=n;i++){
			cin>>a[i];
			maxa=max(a[i],maxa);
		}
		if(maxa==1){
			//15 to 20
			res=1;
			for(int i=4;i<=n;i++){
				res=2*res+3*(i-3);
//				cout<<res<<endl;
				res%=MOD;
			}
			cout<<res;
		}else{
//			if(n<=20){
				//4 to 10
				vector<int> v;
				v.push_back(1);
				for(int i=1;i<=n-2;i++){
					v[0]=i;
					dfs(1,v);
				}
				cout<<res;
//			}
		}
	}
}
