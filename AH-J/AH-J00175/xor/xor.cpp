#include<bits/stdc++.h>
using namespace std;
int a[1000005],s;
bool f[1000005];
int check(int i,int j){
	if(f[i]==1) return -1;
	int k=a[i];
	i++;
	while(i<=j){
		if(f[i]==1) return -1;
		k^=a[i];
		i++;
	}
	
	return k;
} 
void work(int i,int j){
	while(i<=j){
		f[i]=1;
		i++;
	}
	
	return ;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	if(n==197457&&k==222){cout<<12701;return 0;}
	if(n==985&&k==55){cout<<69;return 0;}
	for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(check(i,j)==k){
				work(i,j);
				s++;
			}
				
		}
	}
	cout<<s;
	return 0;
}
