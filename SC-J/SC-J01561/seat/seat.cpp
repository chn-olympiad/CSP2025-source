#include<bits/stdc++.h> 
using namespace std;


int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int a[101],c[101];
	bool b[101];
	
	for(int i=1;i<=100;i++){
		b[i]=0;
	}
	
	cin>>n>>m;
	int u=n*m;
	for(int i=1;i<=u;i++){
		cin>>a[i];
	}
	
	for(int i=1;i<=u;i++){
		b[a[i]]=true;
	}
	
	
	int ming=a[1];
	
	int count=1;
	int counti=1;
	for(int i=100;i>=1;i--){
		if(b[i]&&i){
			c[count++]=i;
		}
	}
	
	
	for(int i=1;i<=count;i++){
		
		if(c[i]==ming){
			counti=i;
		}
	}
	
	
	int sha=counti/n,yu=counti%n;
	int hang,lie;
	
	if(sha%2!=0){
		if(yu){
			lie=sha+1;
			hang=n-yu+1;
		}
		else{
			lie=sha;
			hang=n;
		}
	}
	else{
		if(yu){
			lie=sha+1;
			hang=yu;
		}
		else{
			lie=sha;
			hang=1;
		}
	}
	
	cout<<lie<<" "<<hang;
	return 0;
}