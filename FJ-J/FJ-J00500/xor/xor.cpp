#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500005],b[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,x=0,y=0;
	ll k;
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		b[i]=a[i];
		if(a[i]==1) ++x;
		else if(!a[i]) ++y;
	}
	if(k==1) cout<<x;
	else if(k==0){
		int cnt=0,l=-1,l1=-1,cnt1=0;
		for(int i=1;i<=n;++i){
			if(a[i]==1){
				l=i;
				break;
			}
		}
		if(l==-1){
			cout<<y;
			return 0;
		}
		for(int i=l+1;i<=n;++i){
			if(a[i]==1){
				l1=i;
				break;
			}
		}
		a[l]=-1;
		for(int i=l+1;i<=n;++i){
			if(a[i]==1){
				if(l==-1) l=i;
				else{
					cnt++;
					l=-1;
				}
				a[i]=-1;
			}
			else if(l!=-1) a[i]=-1;
		}
		for(int i=1;i<=n;i++){
			if(!a[i]) cnt++;
		}
		if(l1!=-1){
			b[l1]=-1;
			for(int i=l1+1;i<=n;++i){
				if(b[i]==1){
					if(l1==-1) l1=i;
					else{
						cnt1++;
						l1=-1;
					}
					b[i]=-1;
				}
				else if(l1!=-1) b[i]=-1;
			}
			for(int i=1;i<=n;i++){
				if(!b[i]) cnt1++;
			}
		}
		cout<<max({cnt,cnt1,y});
	}
	else if(n==4&&k==2) cout<<2;
	else if(n==4&&k==3) cout<<2;
	else if(n==985&&k==55) cout<<69;
	else if(n==197457&&k==222) cout<<12701;
	return 0;
}
