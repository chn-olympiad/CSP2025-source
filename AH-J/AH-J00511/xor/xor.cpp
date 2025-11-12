#include<bits/stdc++.h>
using namespace std;
int ar[5050];
int a[25][5050],r[25];
priority_queue<array<int,2>,vector<array<int,2>>,greater<array<int,2>>> q;
signed main(){
	freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
	int n,k;cin>>n>>k;
	int kkk=k;
	int pos=1;
	while(k>0){
		r[pos]=k%2;
		pos++;
		k/=2;	
	}
	k=kkk;
	for(int i=1;i<=n;i++)
	{
		cin>>ar[i];pos=1;
		while(ar[i]>0){
		a[pos][i]=ar[i]%2;
		pos++;
		ar[i]/=2;	
		}
	}
	for(int i=1;i<=n;i++){
			for(int j=1;j<=20;j++)		{
				a[j][i]+=a[j][i-1];
			}
		}
		
	for(int i=0;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			bool uuu=1;
			for(int k=1;k<=20;k++){
			if((a[k][j]-a[k][i])%2!=r[k]%2){
			//	cout<<r[k]%2<<' '<<(a[k][j]-a[k][i])%2<<'\n';
				uuu=0;//cout<<i<<' '<<j<<' '<<k<<'\n';
				k=20;
				
				}
			}
			if(uuu){
				q.push({j,i+1});//cout<<j<<' '<<i+1<<'\n';
			}
			
		}
	}
	
	int r=0,ans=0;
	while(r<=n&&!q.empty()){
		//cout<<q.top()[0]<<' '<<q.top()[1]<<'\n';
		if(q.top()[1]>r){
			r=q.top()[0];ans++;
			
		}
		else while(q.top()[1]<=r&&!q.empty()) q.pop();
		//cout<<r<<'\n';
	}
	cout<<ans;
}
