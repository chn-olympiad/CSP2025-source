#include<bits/stdc++.h>
#define int long long
#define MX 5000005
#define MK 200005
//50 maybe->70
const int B=857,mod=1000000009;
using namespace std;int read();
int n,Q,cnt=4,x[MK],y[MK],L[MK],R[MK],w[MK],qp[MX],h[MX];
string a,b;vector<int> v[MK];
int hsh(int l,int r){
	return (h[r]+mod-(h[l-1]*qp[r-l+1]%mod))%mod;}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>Q;
	for(int o=1;o<=n;o++){
		cin>>a>>b;
		int m=a.size(),p=-1,q=-1,nw;
		for(int i=0;i<m;i++){ if(a[i]!=b[i]){
			q=i;if(p<0){p=i;}}}
		if(p<0) continue;
		nw=0;
		L[o]=-p,R[o]=m-1-p;
		w[o]=q-p+1;
		for(int i=p;i<=q;i++){	
			int aw=a[i]-'a'+1;	
			int bw=b[i]-'a'+1;
			nw=(nw*B+aw*27+bw)%mod;
		}x[o]=nw*MX+w[o];w[o]=x[o];
		nw=0;
		for(int i=0;i<m;i++){	
			int aw=a[i]-'a'+1;	
			nw=(nw*B+aw)%mod;
		}y[o]=nw;
		//cout<<L[o]<<' '<<R[o]<<' '<<w[o]<<' '<<x[o]<<' '<<y[o]<<'\n';
	}
	sort(w+1,w+1+n);
	for(int o=1;o<=n;o++){
		int nw=lower_bound(w+1,w+1+n,x[o])-w;
		v[nw].emplace_back(o);
	}
	while(Q--){
		cin>>a>>b;
		if(a.size()!=b.size()){
			cout<<"0\n";continue;}
		int m=a.size(),p=-1,q=-1,nw;
		qp[0]=1;
		for(int i=1;i<=m;i++)
			qp[i]=qp[i-1]*B%mod;
		for(int i=0;i<m;i++){ if(a[i]!=b[i]){
			q=i;if(p<0){p=i;}}}
		nw=0;
		for(int i=0;i<m;i++){	
			int aw=a[i]-'a'+1;
			nw=(nw*B+aw)%mod;
			h[i+1]=nw;
		}
		nw=0;
		for(int i=p;i<=q;i++){	
			int aw=a[i]-'a'+1;	
			int bw=b[i]-'a'+1;
			nw=(nw*B+aw*27+bw)%mod;
		}nw=nw*MX+(q-p+1);
		int fd=lower_bound(w+1,w+1+n,nw)-w;
		if(fd>n || w[fd]!=nw){
			cout<<"0\n";continue;}
		//cout<<nw<<'\n';
		int cnt=0;
		for(auto i:v[fd]){
			int ql=p+L[i]+1,qr=p+R[i]+1;
			//cout<<i<<" "<<ql<<' '<<qr<<'\n';
			if(ql<1 || qr>m) continue;
			int gt=hsh(ql,qr);
			//cout<<"--> "<<gt<<'\n';
			if(gt!=y[i]) continue;
			cnt++;
		}cout<<cnt<<'\n';
	}
	return 0;
}