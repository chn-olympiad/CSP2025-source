#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","w",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	int t;
	int ans=0;
	cin>>t;
	for(int i=1;i<n*m;i++){
		int c;
		cin>>c;
		if(c>t){
			ans++;
		}
		
	} 
	int x,y;
	if(ans==0){
		cout<<1<<" "<<1<<endl;
	}
	x=ans/n;
	cout<<x+1<<" ";
	y=ans%n;
	if(x&1){
		cout<<n-y<<endl;
	}else{
		cout<<y+1<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
