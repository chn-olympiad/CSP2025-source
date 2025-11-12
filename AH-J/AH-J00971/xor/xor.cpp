#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long b[500005];
int n,k;
int bit[30],bit1[30];
int s1=0,s2=0;
struct node{
	int l,r;
}w[500005];
bool cmp(node a,node b){
	return a.r<b.r;
}
int ss=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]^a[i];
	}	
	int K=k;
	while(K){
		bit[++s1]=K%2;
		K/=2;
	}
	for(int i=1,j=s1;i<=j;i++,j--){
		swap(bit[i],bit[j]);
	} 
	for(int i=1;i<=n;i++){
		memset(bit1,0,sizeof(bit1));
		s2=0;
		K=b[i];
		while(K){
			bit1[++s2]=K%2;
			K/=2;
		}
		for(int k=1,j=s2;k<=j;k++,j--){
			swap(bit1[k],bit1[j]);
		}
		if(s2==0) s2=s1;
		long long wt=0,tw=1;
		for(int j=max(s1,s2);j>=1;j--){
			if(bit1[j]==bit[j]) {
				tw*=2;
				continue;
			}
			wt+=tw;
			tw*=2;
		}
		int j=i-1;
		while(j>=0){
			if(b[j]==wt){
				w[++ss]={j+1,i};
				break;
			}
			j--;
		}
		
	}
	int ans=1,R=w[1].r;
	for(int i=2;i<=ss;i++){
		if(w[i].l>R){
			ans++,R=w[i].r;
		}
	}
	cout<<ans<<endl;
	return 0;
}
