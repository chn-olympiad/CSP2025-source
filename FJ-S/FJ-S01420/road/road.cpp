#include<bits/stdc++.h>
using namespace std;
int a,b,c,x[1000005],y[1000005],z[1000005],s;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>a>>b>>c;
	int sum=0;
	for (int i=0;i<b;i++){
		cin>>x[i]>>y[i]>>z[i];
		sum+=x[i];
	}
	for (int i=0;i<c;i++){
		cin>>s>>s>>s>>s>>s;
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdin);
	return 0;
} 
