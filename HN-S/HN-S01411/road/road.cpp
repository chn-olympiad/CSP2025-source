#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10050;
typedef unsigned long long ll;

struct tu{
	int now;
	int to;
	int nxt;
	ll len;
}a[3000000];

int rc[MAXN];
bool chk[MAXN];
ll bwd[MAXN];
ll bwk[21];

int n,m,k,cnt;

ll ttl;

void dij(){
	priority_queue <pair<ll,int> > pq;
	pq.push(make_pair(0,1));
	while(!pq.empty()){

		int t=pq.top().second;
		pq.pop();
		
		if(chk[t]) continue;
		
		//cout<<"==="<<t<<" bwd= "<<bwd[t]<<"===\n";
		
		chk[t]=true;
		ttl+=bwd[t];
		int tmp=rc[t];
		
		while(tmp){
			
			ll t2=a[tmp].len;
				
			if(a[tmp].to<=n){
				if(t>n) t2+=(bwk[t-n]-bwk[t-n+10]);
				if(t2<bwd[a[tmp].to]){
					bwd[a[tmp].to]=t2;
					pq.push(make_pair(bwd[a[tmp].to]*-1,a[tmp].to));
				}
				//	cout<<"now= "<<a[tmp].now<<" to="<<a[tmp].to<<" nxt= "<<a[tmp].len<<'\n';
			}
				
			else{
				if(t2<bwk[a[tmp].to-n]){
					bwk[a[tmp].to-n]=t2;
					pq.push(make_pair(bwk[a[tmp].to-n]*-1,a[tmp].to));
				//cout<<bwk[a[tmp].to-n]<<" bwk==++==\n";
				}				
			}
				
			tmp=a[tmp].nxt;	
		}
	}
}

void adde(int anow,int ato,int alen){
	a[++cnt].now=anow;
	a[cnt].to=ato;
	a[cnt].len=alen;
	a[cnt].nxt=rc[anow];
	rc[anow]=cnt;
	return;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	
	cin>>n>>m>>k;
	for(int i=2;i<=n;i++){
		bwd[i]=INT_MAX;
	} 
	
	for(int i=1;i<=k;i++){
		bwk[i]=INT_MAX;
	} 
	
	for(int i=1;i<=m;i++){
		int t1,t2,t3;
		cin>>t1>>t2>>t3;
		adde(t1,t2,t3);
		adde(t2,t1,t3);
	}
	
	for(int i=1;i<=k;i++){
		cin>>bwk[i+10];
		for(int j=1;j<=n;j++){
			int t3;
			cin>>t3;
			adde(i+n,j,t3+bwk[i+10]);
			adde(j,i+n,t3+bwk[i+10]);
		}
	}
	
	dij();
	
	cout<<ttl;
	
	fclose(stdin);
	//fclose(stdout);
	
	return 0;
}
