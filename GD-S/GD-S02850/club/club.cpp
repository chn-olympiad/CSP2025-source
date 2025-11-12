#include<bits/stdc++.h>
#define endl '\n' 
#define N 10005
using namespace std;
int w1[N],w2[N],w3[N];
int tot=0;int d[4];
int mx(int p){
	if(w1[p]>=w2[p]&&w1[p]>=w3[p])return 1;
	if(w2[p]>=w1[p]&&w2[p]>=w3[p])return 2;
	if(w3[p]>=w2[p]&&w3[p]>=w2[p])return 3;
} 
int main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	
	int t,n;
	cin>>t;
	for(int k=1;k<=t;++k){
		cin>>n;
		bool flag=true;
		for(int i=1;i<=n;++i){
			cin>>w1[i]>>w2[i]>>w3[i];
			if(flag)if(w2[i]!=w3[i])flag=false;
		}
		
		if(flag){
			sort(w1+1,w1+1+n);
			for(int i=n/2+1;i<=n;++i)
				tot+=w1[i];
			cout<<tot;
			tot=0;
			continue;
		}
		
		for(int i=1;i<=n;++i){
//			if(d[mx(i)]<=n/2)++d[mx(i)];
//			else {
//				w[mx(i)][i]=-1;
//				--i;continue;
//			}
			if(mx(i)==1)tot+=w1[i];
			if(mx(i)==2)tot+=w2[i];
			if(mx(i)==3)tot+=w3[i];
		}
		cout<<tot;
		tot=0;
	}
	
 return 0;
}
