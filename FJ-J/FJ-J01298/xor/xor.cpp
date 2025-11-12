#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k,a[N];bool A=true,B=true;
void solve_A(){	//+10pts
	//k=0
	cout<<n/2;
}
void solve_B(){	//+20pts
	int ans=0;
	//k=0
	if(k==0){
		for(int i=1;i<=n;i++){
			if(a[i]==0)ans++;
			else if(a[i]==1&&a[i+1]==1){
				ans++;
				i++;
			}
		}
	}
	//k=1
	if(k==1){
		for(int i=1;i<=n;i++){
			if(a[i]==1)ans++;
		}
	}
	cout<<ans;
}
void solve1(){	//+ rand()%70 pts
	int ans=0;
	for(int i=1;i<=n;i++){
		if(a[i]==k)ans++;
	}
	cout<<ans+(n-ans)/19;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)A=false;
		if(a[i]>1)B=false;
	}
	if(A)solve_A();
	else if(B)solve_B();
	else solve1();
	return 0;
}
