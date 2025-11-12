#include<bits/stdc++.h>
using namespace std;
int a[500099],b[500099];
int main(){
	freopen("xor.in","r",stdin);freopen("xor.out","w",stdout);
	int n,k; cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int j,h;long long an=0,nd=0;
	for(int i=1;i<=n;i++){
		j=i;h=a[i];
		while(h!=k&&j>=2&&j>=nd){
			j--;
			h=h^a[j];
		}if(h==k){
			b[i]=j;
		}else{
			b[i]=0;
		}
		if(b[i]>nd){
			nd=i;
			an++;
		}
	}
	cout<<an;
	return 0;
	
	
	
	
}
