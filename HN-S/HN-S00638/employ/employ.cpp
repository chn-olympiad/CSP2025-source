#include<bits/stdc++.h>
using namespace std;
const int N=503;
int n,k,ans,a[N],sum=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
    string s;
	cin>>n>>k>>s;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	if(a[i]!=0){
    		ans++;
		}
	}
/*
#include<bits/stdc++.h>
using namespace std;
int u,v,w;
int c[13],d[13][10003],l,ans,sum,f[10003],k,n,m;
struct gz{
	int x,y,z;
}b[100003],x;
vector<gz>a[10003];
bool cmp(gz x,gz y){
	return x.z<y.z;
}
int lxy(){
	sort(b+1,b+1+ans,cmp);
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	int v=0;
	for(sum=0;sum<n-1;){
		v++;
		if(f[b[v].x]!=f[b[v].y]){
			sum++;
			f[b[v].y]=b[v].x;
			ans+=b[v].z;
		}
	}
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
    	cin>>u>>v>>w;
    	gz x.x=u;x.y=v;x.z=w;
    	a[u].push_back(x);b[++ans]=gz;
    	swap(x.x,x.y);
    	a[v].push_back(x);b[++ans]=gz;    	
	} 
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>d[i][j];
		}for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				gz x.x=i,x.y=j,x.z=d[i][j]+d[i][k];
				if(j!=k){
				   	
				}
			}
		}
	}

	return 0;
}

*/
	sort(a+1,a+1+n);
    if(n-ans<k){
    	cout<<0;
	}else{
		for(int i=ans+1;i<=n;i++){
			sum=(sum*i)%998244353;
		}cout<<sum;
	}
	return 0;
}

