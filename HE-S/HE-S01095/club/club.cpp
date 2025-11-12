#include<bits/stdc++.h>
using namespace std;
long long n,da,db,dc;
int MAX(int a,int b,int c){
	cin>>a>>b>>c;
	if(a>b&&a>c){
		return a;
	}else if(b>a&&b>c){
		return b;
	}else if(c>a&&c>b){
		return c;
	}
}
int d[3]={1,2,3};
int a[100][100];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);	
	cin>>n; 
	while(n--){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;i++){
			cin>>a[i][j];
			}
		}
		long long a,b,c;
		long long ans=0; 
		ans=MAX(a,b,c);
		if(ans==a) da++;
		if(ans==b) db++;
		if(ans==c) dc++;
	}
	cout<<da<<endl;
	cout<<db<<endl;
	cout<<dc<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
