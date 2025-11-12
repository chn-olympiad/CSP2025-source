#include<bits/stdc++.h>
using namespace std;
long long n,m,k,c[15],a[12][10044],f[800044],xe,ye,op=0,bk=0,ed=0,m2=0,m3=0;
struct one{
	long long u,w;
};
struct two{
	int u,v;
	long long w,q;
}b[2000006],b2[100005],b3[200005];
bool cmp(two a1,two b1){
	return a1.w<b1.w;
}
vector<one> v[10044];
inline int find(int a1){
	if(f[a1]==a1){
		return a1;
	}
	else{
		f[a1]=find(f[a1]);
		return f[a1];
	}
}
bool bo[13];
inline void abc(long long a1){
	if(a1==k+1){
		long long op2=0;
		for(int i=1;i<=m2;i++){
			b3[i]=b2[i];
		}
		m3=m2;
		for(int i=1;i<=k;i++){
			if(bo[i]==1){
				op2+=c[i];
				for(int j=1;j<=n;j++){
					++m3;
					b3[m3].u=n+i;
					b3[m3].v=j;
					b3[m3].w=a[i][j];
				}
			}
		}	
		sort(b3+1,b3+m3+1,cmp);
		for(int i=1;i<=n+k;i++){
			f[i]=i;
		}
		for(int i=1;i<=m3;i++){
			xe=find(b3[i].u);
			ye=find(b3[i].v);
			if(xe!=ye){
				f[xe]=ye;
				op2+=b3[i].w;
			}
		}		
		op=min(op2,op);	
	}
	else{
		bo[a1]=1;
		abc(a1+1);
		bo[a1]=0;
		abc(a1+1);
	}
	return ;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		//cin>>b[i].u>>b[i].v>>b[i].w;
		scanf("%lld%lld%lld",&b[i].u,&b[i].v,&b[i].w);
//		v[b[i].u].push_back({b[i].v,b[i].w});
//		v[b[i].v].push_back({b[i].u,b[i].w});
	}
	bk=0;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0){
			bk=1;
		}
		ed=1;
		for(int j=1;j<=n;j++){
			scanf("%lld",&a[i][j]);
			if(a[i][j]==0){
				ed=0;
			}
//			++m;
//			b[m].u=n+i;
//			b[m].v=j;
//			b[m].w=a[i][j];
		}
		if(ed==1){
			bk=1;
		}
	}
	//cout<<bk<<endl;
	if(bk==0){
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				++m;
				b[m].u=n+i;
				b[m].v=j;
				b[m].w=a[i][j];
			}
		}	
		//cout<<1111<<endl;
		sort(b+1,b+m+1,cmp);
		for(int i=1;i<=n+k;i++){
			f[i]=i;
		}
		//cout<<n+k<<endl;
		for(int i=1;i<=m;i++){
			//cout<<b[i].u<<" "<<b[i].v<<endl;
			xe=find(b[i].u);
			ye=find(b[i].v);
			if(xe!=ye){
				//cout<<xe<<" "<<ye<<endl;
				f[xe]=ye;
				op+=b[i].w;
			}
		}
		cout<<op<<endl;	
	}
	else{
		sort(b+1,b+m+1,cmp);
		for(int i=1;i<=n;i++){
			f[i]=i;
		}
		for(int i=1;i<=m;i++){
			xe=find(b[i].u);
			ye=find(b[i].v);
			if(xe!=ye){
				m2++;
				b2[m2].u=b[i].u;
				b2[m2].v=b[i].v;
				b2[m2].w=b[i].w;
				f[xe]=ye;
				op+=b[i].w;
			}
		}
		abc(1);
		cout<<op<<endl;	
	}
	return 0;
}
