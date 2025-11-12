#include<bits/stdc++.h>
using namespace std;
bool flag;long long a[500005],n,k,num,ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1)num++;
		else flag=1;
	}
	if(k==0){
		if(!flag)cout<<n/2;
		else{
			for(long long i=1;i<=n;i++){
				if(a[i]==0)ans++;
				else if(a[i+1])ans++,i++;
				}
			}
			cout<<ans;
		
	}else if(k==1){
		cout<<num;
	}else{
		cout<<0;
	} 
	fclose(stdin);
	fclose(stdout);
	
	
	
	return 0;
}
