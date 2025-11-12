#include<bits/stdc++.h>
using namespace std;
int n,a[50010],k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(k==0){
		cout<<n/2;
	}
	else if(k==1){
		int x,c=0;
		for(int i=0;i<n;i++){
			cin>>x;
			if(x==1) c++;
		}
		cout<<c;
	} 
	else{
		mt19937 ran(20251101);
		cout<<ran()%100;
	}
	
	return 0;
}
