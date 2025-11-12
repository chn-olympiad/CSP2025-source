#include<bits/stdc++.h>
using namespace std;
const int N=1e6+8;
string s;
int st[N],num[N];
struct node{
	int l,r;
	
};
int main(){
	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	node l[99999];
	int h=0;
	
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int k,m; 
	cin>>m>>k;
	for(int i=0;i<m;i++)cin>>num[i];
	
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			if(i<j) continue;
			long long x=num[j];
			for(int z=j+1;z<=i;z++){
				x^=num[z];
			}
			if(x==k){
				l[++h].l=j;
				l[h].r=i;
			}
		}
	}
	int q=2,a=l[1].l,b=l[1].r,ans=1;
	cout<<h<<" ";
	if(h!=0){
		
		while(h>1){
			int x=l[q].l;
			int y=l[q].r;
			if(b>=x){
				h--;
				q++;
				continue;
			}else{
				ans++;
				a=x;
				b=y;
			}
			h--;
			q++;
		}
	}else{
		cout<<0;
		return 0;
	}
	cout<<ans;
	return 0;
} 