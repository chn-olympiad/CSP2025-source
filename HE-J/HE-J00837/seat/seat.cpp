#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n,m,i,k,c,a=1,b=1;
	cin>>n>>m>>k;
	for(i=0;i<n*m;i++){
		cin>>c;
		if(c>k){
			if(b==n){
				b=0;
				a++;
			}
			b++;
		}
	}
	if(a%2==0){
		b=n-b+1;
	}
	cout<<a<<" "<<b;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
