#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
long long t,n,sum[5],ans,h;
struct member{
	int val[5],maxx,minn,mid;
	bool f;
} a[N];

bool cmp1(member x,member y){
	return x.val[x.maxx]-x.val[x.mid]>y.val[y.maxx]-y.val[y.mid];
}

bool cmp2(member x,member y){
	if(y.f){
		return 0;
	}
	if(x.f){
		return 1;
	}
	return abs(x.val[h%3+1]-x.val[(h+1)%3+1])>abs(y.val[h%3+1]-y.val[(h+1)%3+1]);
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			int ma=0,mi=INT_MAX,x;
			a[i].f=0;
			for(int j=1;j<=3;j++){
				cin>>x;
				a[i].val[j]=x;
				if(x>ma){
					ma=x;
					a[i].maxx=j;
				}
				if(x<=mi){
					mi=x;
					a[i].minn=j;
				}
			}
			a[i].mid=6-a[i].maxx-a[i].minn;
		}
		sort(a+1,a+n+1,cmp1);
		sum[1]=0;
		sum[2]=0;
		sum[3]=0;
		ans=0;
		int i=1;
		for(;i<=n;i++){
			if(sum[a[i].maxx]<n/2){
				sum[a[i].maxx]++;
				ans+=a[i].val[a[i].maxx];
				a[i].f=1;
			}
			else{
				h=a[i].maxx;
				break;
			}
		}
		sort(a+i,a+n+1,cmp2);
		for(;i<=n;i++){
			if(a[i].f){
				continue;
			}
			if(sum[a[i].maxx]<n/2){
				sum[a[i].maxx]++;
				ans+=a[i].val[a[i].maxx];
			}
			else if(sum[a[i].mid]<n/2){
				sum[a[i].mid]++;
				ans+=a[i].val[a[i].mid];
			}
			else{
				sum[a[i].minn]++;
				ans+=a[i].val[a[i].minn];
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
//FJ-S00097
