#include<bits/stdc++.h>
using namespace std;
int num[110];
int main(){
	freopen("seat.in","r",stdin); 
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int tmp=n*m;
	for(int i=1;i<=tmp;i++){
		cin>>num[i];
	}
	int a=num[1],hang=0,lie=0;
	sort(num+1,num+1+tmp);
	for(int i=tmp;i>=1;i--){
		if(num[i]==a){
			int k=tmp-i;
			lie=k/n+1;
			cout<<lie<<' ';
			if(lie%2==1){
				cout<<k%n+1;
			}
			else cout<<n-(k%n)+1;
			return 0;
		} 
	}
	return 0;
} 
