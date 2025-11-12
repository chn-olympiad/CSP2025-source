#include<bits/stdc++.h>
using namespace std;

int n,m,arr[105],c=1,r,cnt;

bool big(int a,int b){
	return a>b;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>arr[i];
	int sc=arr[1]; 	//先表示分数后表示名次 
	sort(&arr[1],&arr[n*m+1],big);
	
	for(int i=1;i<=n*m;i++){
		if(arr[i]==sc){
			sc=i;
			break; 
		} 
	}
		
	while(sc>n){
		sc-=n;
		c++;
		cnt=!cnt; //0表示向下数，1表示向上数 
	}
	if(cnt==0) cout<<c<<" "<<sc;	
	else cout<<c<<" "<<n-sc+1;
	
	return 0;
}
