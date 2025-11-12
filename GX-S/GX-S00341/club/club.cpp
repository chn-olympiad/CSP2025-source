#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,a1[100001],a2[100001],a3[100001],sum=0,sum1=0;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a1[i]>>a2[i]>>a3[i];
			if(a2[i]==0 && a3[i]==0){
				sum=50000*a1[i];
			}else{
				sum1=max(a1[i],a2[i]);
				sum+=max(sum1,a3[i]);
			}
			
		}
		cout<<sum<<endl;
		sum=0;
		//wo yao shang 2 deng awa
	}
	return 0;
}
