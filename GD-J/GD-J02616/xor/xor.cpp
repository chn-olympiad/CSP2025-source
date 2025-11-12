#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+10;
long long n,m,k,arr[N],ans=0;
bool take[N];
void dfs(int fr,int fin,int c){
	int bz=0;
	if(fin>n||take[fr]==1||take[fin]==1){
		return;
	}
	if(c==k){
		for(int i=fr;i<=fin;i++){
			if(take[i]==1){
				bz=1;
				break;
			}
		}
		
		if(bz==0){
			for(int i=fr;i<=fin;i++){
				take[i]=1;
			}
			ans++;
			
			//cout<<fr<<" "<<fin<<endl;
		}
	
	}

	if(fin+1<=n){
		dfs(fr+1,fin+1,arr[fin+1]);
		dfs(fr,fin+1,c^arr[fin+1]);
		
	}

}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	
	dfs(1,1,arr[1]);
	
	cout<<ans;
	return 0;
} 
