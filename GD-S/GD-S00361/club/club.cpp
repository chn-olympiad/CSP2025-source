#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct Node{int id,mi;}b[N];
int n, T, a[N][4], sum, f[N], cnt[N];
bool cmp(Node x,Node y){return x.mi>y.mi;}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		sum=cnt[1]=cnt[2]=cnt[3]=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++)
				cin>>a[i][j];
			if(a[i][3]>a[i][2]) f[i]=3, sum+=a[i][3], cnt[3]++;
			else f[i]=2, sum+=a[i][2], cnt[2]++;
			b[i]={i,a[i][1]-a[i][f[i]]};
		}
		sort(b+1,b+n+1,cmp);
		for(int i=1;i<=n && cnt[1]<n/2;i++){
			if(b[i].mi>0)
				cnt[1]++, cnt[f[b[i].id]]--, sum+=b[i].mi;
			else{
				if(cnt[2]<=n/2 && cnt[3]<=n/2) break;
				if(cnt[2]>n/2 && f[b[i].id]==2)
					cnt[2]--, cnt[1]++, sum+=b[i].mi;
				if(cnt[3]>n/2 && f[b[i].id]==3)
					cnt[3]--, cnt[1]++, sum+=b[i].mi;
			}
		}
		cout<<sum<<"\n";
	}
	return 0;
} 
