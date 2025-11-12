#include<bits/stdc++.h>
using namespace std;
int n,k,ans,m;
bool f;
int v[1005],a[1005],er[1005][9];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
		if(a[i]==k){
			ans++;
			v[i]=1;
		}
	}
	
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			f=true;
			memset(er,0,sizeof(er));
			
			for(int l=i;l<=j;l++){
				//cout<<v[l]<<l;
				if(v[l]==1)f=false;
			}
			if(f==false)break;
			for(int l=1;l<=n;l++){
				int h=8;
				m=a[l];
				while(m){
						er[l][h]=m%2;
						m/=2;
						h--;
				}
	}
			for(int l=i;l<=j;l++){
				//cout<<er[l][7]<<er[l][8]<<er[l+1][7]<<er[l+1][8];
				for(int r=8;r>0;r--){
					
					if(er[l][r]==er[l+1][r])er[l+1][r]=0;
					else if(er[l][r]!=er[l+1][r])er[l+1][r]=1;
				}
				//cout<<er[l+1][7]<<er[l+1][8]<<endl;
			}
			
			
			int sum=er[j][1]*2*2*2*2*2*2*2+er[j][2]*2*2*2*2*2*2+er[j][3]*2*2*2*2*2+er[j][4]*2*2*2*2+er[j][5]*2*2*2+er[j][6]*2*2+er[j][7]*2+er[j][8];
			if(sum==k){
				for(int l=i;l<=j;l++){
					v[l]=1;
				}
				ans++;
			}
			//cout<<i<<" "<<j<<" "<<sum<<" "<<ans<<endl;
		}
	}
	cout<<ans;
	return 0;
}
