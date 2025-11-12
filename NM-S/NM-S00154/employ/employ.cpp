#include<bits/stdc++.h>
using namespace std;
long long int n,m;
char ti[100000];
long long int ren[1000000];
long long int ren1[1000000];
long long int ans;
int a[1000000];
int as;
int po;
int jianyan(int x){
	as=0;
	po=0;
	for(int i=1;i<=n;i++){
		if((a[i]<i-1)||(a[i]<as)||(ti[i]=='0')){
			as+=1;
		}else {
			as=0;
			po+=1;
		}
		cout<<a[i];
	}
	cout<<po<<endl;
	if(po>=m){
		ans+=1;
	}
}
void shai1(long long int x){
	if(x>n){
		int t=jianyan(1);
	}else{
		for(int i=1;i<=n;i++){
			if(ren1[i]==1){
				ren1[i]=0;
				a[x]=ren[i];
				
					shai1(x+1);
				
				ren1[i]=1;
			}
		}
	}
	
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","W",stdout);
	cin>>n>>m;
	for(long long int i=1;i<=n;i++){
		cin>>ti[i];
	}
	for(long long int i=1;i<=n;i++){
		cin>>ren[i];
		ren1[i]=1;
	}
	shai1(1);
	cout<<ans%998244353;
	return 0;
} 
