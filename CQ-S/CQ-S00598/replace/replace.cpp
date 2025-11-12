#include<bits/stdc++.h>
using namespace std;
const int N=1000+5;
int n,q;
string a[N],b[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		a[i]=" "+a[i];
		b[i]=" "+b[i]; 
	}
	while(q--){
		string x,y;
		cin>>x>>y;
		x=" "+x;
		y=" "+y;
		string u=x;
		int lx=x.size()-1;
		int ans=0;
		for(int i=1;i<=n;i++){
			int la=a[i].size()-1;
			for(int j=1;j<=lx-la+1;j++){
				//cout<<j<<" "<<lx-la+1<<endl;
				bool f=0;
				for(int k=j;k<=j+la-1;k++){
					//cout<<k<<" "<<i<<" "<<k-j+1<<" "<<x[k]<<" "<<a[i][k-j+1]<<endl;
					if(x[k]!=a[i][k-j+1]){
						f=true;
						break;
					}
				}
				//cout<<f<<endl;
				if(!f){
					//cout<<i<<" "<<j<<endl;
					u=x;
					for(int k=j;k<=j+la-1;k++){
						//cout<<k<<" "<<i<<" "<<k-i+1<<
						u[k]=b[i][k-j+1];
					}
					if(u==y){
						ans++;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
