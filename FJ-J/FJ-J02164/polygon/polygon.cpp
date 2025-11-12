#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,mod=998244353;
int n,ans=0;
int l[N],cho[N];
int main(){
	freopen("polygon.in","r",stdin);
	freoprn("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>l[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int maxl=-1,suml=0;
			int o=1;
			for(int k=i;k<=j;k++){
				suml+=l[k];
				cho[o]=l[k];
				o++;
				maxl=max(maxl,l[k]);
			}
			if(suml>2*maxl){
//				for(int a=1;a<o;a++){
//					cout<<cho[a]<<" ";
//				}
//				cout<<endl<<suml<<endl;
				ans++;
			}
		}
		
	}
	cout<<ans%mod;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
