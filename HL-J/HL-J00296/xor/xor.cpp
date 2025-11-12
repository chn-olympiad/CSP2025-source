#include<bits/stdc++.h>
using namespace std;
long long key[500005];
long long m[500005];
long long xr[1005][1005];
map<int,int>op;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	vector<int>a(n+1);
	int l=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int la=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int c=0;
			if(i==j){
				xr[i][j]=a[i];
			}
			else{
				xr[i][j]=xr[i][j-1]^a[j];
				
			}
			if(xr[i][j]==k){
				key[l]=i;
				op[i]=j;
				cout<<i<<" "<<j<<" "<<xr[i][j]<<" "<<xr[i][j-1]<<" "<<i<<" "<<a[i]<<endl;
				la=max(la,j);
				l++;
				m[i]=1;
			}
			
		}
	}
	m[0]=0;
	for(int j=0;j<l;j++){
		for(int i=la;i>0;i--){
			if(i>=op[key[j]]){
				m[i]=max(m[i],m[key[j]-1]+1);
			}
			else{
				m[i]=m[i];
			}
		
			
		}
	}
	cout<<endl;
	cout<<m[la]
	return 0;
}
