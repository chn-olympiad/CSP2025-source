#include<bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
const int N=500005;
struct node{
	int l,r;
}f[N];
int dis;
int main(){
//	IOS;
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int* a=new int[n+5];
	int* s=new int[n+5];
	s[0]=0;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	for(int i=1;i<=n;++i){
		bool b=0;
		for(int j=n;j>=i;--j){
			if((s[j]^s[i-1])==k){
				if(b==0){
					++dis;
					b=1;
				}
				f[dis].l=i;
				f[dis].r=j;
//				cout<<i<<' '<<j<<endl;
			}
		}
	} 
	bool is_return=0;
	if(dis==0){
		cout<<0;
		is_return=1;
	}
	if(is_return==0){
		int cnt=1,diss=2;
		node pre=f[1];
		while(diss<=dis){
			if(f[diss].l>pre.r){
				cnt++;
				pre=f[diss];
			}
			diss++;
		}
		cout<<cnt;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 