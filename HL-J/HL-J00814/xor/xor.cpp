#include<bits/stdc++.h>
using namespace std;
int ll[10001];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ans=0,cnt=0;
	cin>>n>>k;
	for(int i=0;i<n;i++)
	cin>>ll[i];
	for(int i=0;i<n;i++){
		
	
	ans=0;

	for(int j=1;j<n;j++){
		ans=ans+ll[j];
		if(ans==k){
			cnt++;
			i=j;
			break;
			
		}
	}
	
}

cout<<cnt<<endl;

return 0;
}
