#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("fre.in","seat",stdin);
	freopen("fre.out","seat",stdout);
	
	
	int n,m,a[100],r,cnt=1,b=1,c=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[cnt];
			r=a[1];
			if(c>m&&b%2!=0){
				b++;
				c--;
			}
			if(b%2==0&&c<1){
				b++;
				c++;
			}
			if(a[cnt]!=r&&a[cnt]>r&&b%2!=0){
				c++;
			}
			
			if(a[cnt]!=r&&b%2==0&&a[cnt]>r){
				c--;
			}
			cnt++;
		}
	}
	if(c<1){
		c++;
	} else if(c>m){
		c--;
	} 
	cout<<b<<" "<<c;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
