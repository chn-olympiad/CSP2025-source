#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t;
long long n[N];
long long d[5];
long long n1,n2,n3;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n[i];
		if(n[i]%2==1){
			return 0;
		}
		for(int j=1;j<=n[i];j++){
			for(int k=0;k<3;k++){
				cin>>d[k];
			}
		}	
	}
	long long m[N],ans[N];
	for(int i=1;i<=t;i++){
		for(int j=1;j<=n[i];j++){
			if(max(d[0],d[1])==d[0]&&max(d[0],d[2])==d[0]){
				n1+=1;
				m[j]=d[0];
			}else{
				if(max(d[0],d[1])==d[1]&&max(d[1],d[2])==d[1]){
					n2+=1;
					m[j]=d[1];
				}else{
					if(max(d[0],d[2])==d[2]&&max(d[1],d[2])==d[2]){
						n3+=1;
						m[j]=d[2];	
					}
				}
			}
			ans[i]+=m[j];
			m[j]=0;				
		}
		if(n1>n[i]/2){
			return 0;
		}else{
			if(n2>n[i]/2){
				return 0;
			}else{
				if(n3>n[i]/2){
					return 0;
				}
			}
		}
		cout<<ans[i]<<endl;
	}
	return 0;
}
