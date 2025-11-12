#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+10;
long long a[N],k,n,cnt,sum;
struct node{
	int l;
	int r;
}b[N];
bool cmp(node x,node y){
	if(x.l<y.l) return 1;
	else if(x.r<y.r)return 1;
	else return 0;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);	
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>=2) a[i]=a[i]^a[i-1];
		//cout<<a[i]<<" ";
	}
	//cout<<'\n';
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int m=a[i-1]^a[j];
			if(m==k){
				cnt++;
				b[cnt].l=i;
				b[cnt].r=j;
				//cout<<i<<" "<<j<<'\n';
			}else continue;
		}
	}
	sort(b+1,b+cnt+1,cmp);
	int l=b[1].r;
	sum++;
	for(int i=2;i<=cnt;i++){
		if(b[i].l>l){
			sum++;
			l=b[i].r;
		}
	}
	cout<<sum;
	return 0;
}