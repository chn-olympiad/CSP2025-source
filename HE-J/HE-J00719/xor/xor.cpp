#include<bits/stdc++.h>
using namespace std;
int b[510101],a[501010];
map<int,int> m;
int n,k;
int ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	cin>>b[1];
	//a[1]=b[1];
	for(int i=2;i<=n;i++){
		cin>>b[i];
		//a[i]=a[i-1]^b[i];
	}
	int x=-1;
	for(int i=1;i<=n;i++){
		int xp=b[i] xor xp;
		int op=xp xor k;
		if(m[op]>x&&m[op]!=0&&op!=0){
			x=i;
			xp=0;
			ans++;
		}
		else if(op==0){
			x=i;
			xp=0;
			ans++;
		}
		m[xp]=i;
		//cout<<xp<<' '<<op<<' '<<m[op]<<' '<<ans<<"\n";
	}
	cout<<ans;
	return 0;
}

