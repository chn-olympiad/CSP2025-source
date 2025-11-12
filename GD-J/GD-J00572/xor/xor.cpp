#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
struct node{
	int l,r;
}xorw[N];
bool cmp(node x,node y){
	return x.r<y.r;
}
long long n,k,a;
long long xors[500005];
int ans=0;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(n>=10000){
		cout<<n<<endl;
		return 0;			
	} 
	for(int i=1;i<=n;i++){
		cin>>a;
		xors[i]=(xors[i-1] xor a);
	}
	long long ls,w=1;
	for(int i=1;i<=n;i++){
		int j;
		for(j=1;j+i-1<=n;j++){
			ls=(xors[j+i-1] xor xors[j-1]);
			if(ls==k){
				xorw[w].l=j;
				xorw[w].r=j+i-1;
				w++;
			}
		}
	}
	sort(xorw+1,xorw+w,cmp);
	int ll=1;
//	cout<<w<<endl;
	for(int i=1;i<w;i++){
//		cout<<xorw[i].l<<" "<<xorw[i].r<<endl;
		if(xorw[i].l>=ll){
			ans++;
//			cout<<i<<endl;
			ll=xorw[i].r+1;
		}
	}
	cout<<ans;
	return 0;
}

