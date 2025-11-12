#include<bits/stdc++.h>
using namespace std;
#define gt() getchar()
typedef long long ll;
const int mn=501,mod=998244353;
long long sum;
int k[mn],n,m,s[mn],t[mn];
priority_queue<long long> a;
map<int,int> f;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;k[0]=1;
    for(int i=1;i<=n;i++){
		cin>>t[i];
		}
	for(int i=1;i<=n;i++){
		cin>>s[i];
		}
	sort(s+1,s+1+n);
    if(m==1){
		int tot=0;
		for(int i=1;i<=n;i++){
			if(t[i]){
				a.push(i);
				}
			}
		if(a.empty()){
			cout<<0;return 0;
			}
		for(int i=n;i>0;i++){
			while(!a.empty() and s[i]>a.top()) a.pop();
			if(a.empty()) break;
			tot+=a.size();
		}
		if(tot) sum=1;
		for(int i=1;i<n;i++){
			sum=sum*i%mod;
			}
		cout<<sum*tot%mod;return 0;
	}
	int tot=0,totx=1;
 	for(int i=1;i<=n;i++){
		if(t[i]){
			a.push(i);
			}
		}
	if(a.empty()){
		cout<<0;return 0;
	}   
	for(int i=n;i>0;i++){
		while(!a.empty() and s[i]>a.top()) a.pop();
		if(a.empty()) break;
		if(!k[a.size()])f[++tot]=a.size();
		k[a.size()]++;
	}
	for(int i=1;i<=tot;i++){
		for(int j=1;j<=k[f[tot]];j++){
			totx=totx*f[tot]%mod;
			}
		}
	long long sum1=0;
	if(tot) sum1=sum=1;
	for(int i=1;i<=n-m;i++){
		sum=sum*i%mod;
	}
	for(int i=1;i<=m;i++){
		sum1=sum*i%mod;
		}
	cout<<sum*sum1%mod<<endl;return 0;	
}
