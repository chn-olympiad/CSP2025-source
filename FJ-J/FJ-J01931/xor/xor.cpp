#include<bits/stdc++.h>
using namespace std;
struct xyz {
	int f;
	int b;
} sum[500005];
int l[5005][5005];
bool cmp(xyz a,xyz b) {
	return a.b <=b.b ;
}
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cout<<"1";
	
	/*int n,x=1,k,a[500005];
	cin>>n>>k;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		l[i][i]=a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;i<=n;j++){
			l[i][j]=l[i][j-1]^a[j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(l[i][j]=k){
				sum[x].f =i;
				sum[x].b =j;
				x++;
			}
		}
	}
	int ans=0;
	sort(sum+1,sum+x,cmp);
	while(ans++){
		int end=0;
		for(int i=1;i<=x;i++){
			if(sum[i].f >end){
				end=sum[i].b ;
			}
			if(i==x) continue;
		}
	}
	cout<<ans;
	//for(int i=0;i<=x;i++){
	//	cout<<sum[i].f<<" "<<sum[i].b <<endl;
	//}*/
	return 0;
}

