#include<bits/stdc++.h>
using namespace std;
long long n,m,z,k,a[1000050][3],b[15][10050],c[15],p=INT_MAX,o;
bool f[10050],f1;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	o=n;
	for(int i=1;i<=m;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		p=min(p,a[i][3]);
	}
	if(k!=0){
		for(int i=1;i<=k;i++){
			cin>>c[i];
			for(int j=1;j<=n;j++){
				cin>>b[i][j];
				if(b[i][j]==0&&c[i]==0){
					f[j]=1;
					o--;
				}
				
			}
		}
	}
	if(o==0){
		cout<<z;
		return 0;
	}
    for(int i=1;i<=m;i++){
    	for(int j=i+1;j<=m;j++){
    		if(a[i][3]>a[j][3]){
    			swap(a[i][3],a[j][3]);
    			swap(a[i][2],a[j][2]);
    			swap(a[i][1],a[j][1]);
			}
		}
	}
	if(k==0){
		for(int i=1;i<=n;i++){
			if(f[a[i][1]]==0||f[a[i][2]]==0){
				z+=a[i][3];
				f[a[i][1]]=1;
				f[a[i][2]]=1;
			}
		}	
		cout<<z;
		return 0;
	}
	sort(c+1,c+k+1);
	for(int i=1;i<=k;i++){
		if(c[i]<p){
			z+=c[i];
			for(int j=1;j<=n;j++){
				if(b[i][j]<p&&z+b[i][j]<=p){
					z+=b[i][j];
					f[j]=1;
					f1=1;
				}
			}
			if(f1!=1)
			z-=c[i];
		}
		else{
			break;
		}
	}
	for(int i=1;i<=n;i++){
		if((f[a[i][1]]==0||f[a[i][2]]==0)){
			z+=a[i][3];
			f[a[i][1]]=1;
			f[a[i][2]]=1;
		}
	}	
	cout<<z;
	return 0;
} 
