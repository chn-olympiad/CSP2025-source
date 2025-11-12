#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int p[n*m+2],s,sum=0;
	cin>>s;
	for(int i=1;i<n*m;i++){
		cin>>p[i];
		if(p[i]>s) sum++;
	}
	if(sum<n) cout<<1<<" "<<sum+1;
	else{
		int h1=sum/n,h2=sum%n;
		if(h1%2==0) cout<<h1+1<<" "<<h2+1;
		else cout<<h1+1<<" "<<n-h2;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
