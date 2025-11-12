#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
bool sign[N];
struct st{
	int num;
	int place;
}a[5][N];
bool cmp(st x,st y){
	if(x.num!=y.num)
		return	x.num>y.num;
	return x.place<y.place;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n,sum=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[j][i].num;
				a[j][i].place=i;
			}
		}
		sort(a[1]+1,a[1]+n+1,cmp);
		sort(a[2]+1,a[2]+n+1,cmp);
		sort(a[3]+1,a[3]+n+1,cmp);
		int p=1,a1=1,a2=1,a3=1,w1=1,w2=1,w3=1;
		while(p<=n){
			if(a[1][w1].num>=a[2][w2].num&&a[1][w1].num>=a[3][w3].num){
				if(a1<=n/2&&sign[a[1][w1].place]==0){
					sign[a[1][w1].place]=1;
					sum+=a[1][w1].num;
					p++;
					w1++;
					a1++;
				}
				else{
					w1++;
				}
			}
			else if(a[2][w2].num>=a[1][w1].num&&a[2][w2].num>=a[3][w3].num){
				if(a2<=n/2&&sign[a[2][w2].place]==0){
					sign[a[2][w2].place]=1;
					sum+=a[2][w2].num;
					p++;
					w2++;
					a2++;
				}
				else{
					w2++;
				}
			}
			else if(a[3][w3].num>=a[2][w2].num&&a[3][w3].num>=a[1][w1].num){
				if(a3<=n/2&&sign[a[3][w3].place]==0){
					sign[a[3][w3].place]=1;
					sum+=a[3][w3].num;
					p++; 
					w3++;
					a3++;
				}
				else{
					w3++;
				}
			}
		}
		for(int i=1;i<=n;i++){
			sign[i]=0;
		}
		cout<<sum<<"\n";
	} 
	return 0;
} 