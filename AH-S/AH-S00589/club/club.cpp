#include<bits/stdc++.h>
using namespace std;
int T, n;
long long ans;
struct node{
	long long v1, v2, v3, sum;
}a[100010];
bool cmp(node x, node y){
	if(x.sum == y.sum){
		if(x.v1==y.v1){
			if(x.v2==y.v2) x.v3>y.v3;
			return x.v2>y.v2;
		}
		return x.v1>y.v1;
	}
	return x.sum>y.sum;
}
bool check(long long m){
	long long res = 0;
	int c1=0, c2=0, c3=0;
	for(int i=1; i<=n; i++){
		long long v1=a[i].v1, v2=a[i].v2, v3=a[i].v3;
		if(v3>=v2 && v2>=v1){
			if(c3<n/2){
				c3++;
				res+=v3;
			}else if(c2<n/2){
				c2++;
				res+=v2;
			}else if(c1<n/2){
				c1++;
				res+=v1;
			}
		}else if(v3>=v1 && v1>=v2){
			if(c3<n/2){
				c3++;
				res+=v3;
			}else if(c1<n/2){
				c1++;
				res+=v1;
			}else if(c2<n/2){
				c2++;
				res+=v2;
			}
		}else if(v1>=v3 && v3>=v2){
			if(c1<n/2){
				c1++;
				res+=v1;
			}else if(c3<n/2){
				c3++;
				res+=v3;
			}else if(c2<n/2){
				c2++;
				res+=v2;
			}
		}else if(v1>=v2 && v2>=v3){
			if(c1<n/2){
				c1++;
				res+=v1;
			}else if(c2<n/2){
				c2++;
				res+=v2;
			}else if(c3<n/2){
				c3++;
				res+=v3;
			}
		}else if(v2>=v1 && v1>=v3){
			if(c2<n/2){
				c2++;
				res+=v2;
			}else if(c1<n/2){
				c1++;
				res+=v1;
			}else if(c3<n/2){
				c3++;
				res+=v3;
			}
		}else if(v2>=v3 && v3>=v1){
			if(c2<n/2){
				c2++;
				res+=v2;
			}else if(c3<n/2){
				c3++;
				res+=v3;
			}else if(c1<n/2){
				c1++;
				res+=v1;
			}
		}
	}
	return res >= m;
}
void dfs(int i, long long sum, int c1, int c2, int c3){
	if(i>n){
		ans=max(ans, sum);
		return;
	}
	if(c1<n/2){
		dfs(i+1, sum+a[i].v1, c1+1, c2, c3);
	}
	if(c2<n/2){
		dfs(i+1, sum+a[i].v2, c1, c2+1, c3);
	}
	if(c3<n/2){
		dfs(i+1, sum+a[i].v3, c1, c2, c3+1);
	}
	dfs(i+1, sum, c1, c2, c3);
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		long long z=0, y=0;
		for(int i=1; i<=n; i++){
			cin>>a[i].v1>>a[i].v2>>a[i].v3;
			a[i].sum = a[i].v1+a[i].v2+a[i].v3;
			y += max(a[i].v1, max(a[i].v2, a[i].v3));
		}
		sort(a+1, a+1+n, cmp);
		if(n <= 20){//dfs
			dfs(1, 0, 0, 0, 0);
		}else{
			while(z <= y){
				long long mid = (z+y)/2;
				if(check(mid)){
					z=mid+1;
					ans = mid;
					// cout<<ans<<endl;
				}else{
					y=mid-1;
				}
			}
		}
		cout<<ans<<endl;
		// cout<<"*********************"<<endl;
		ans = 0;
	}
	return 0;
}