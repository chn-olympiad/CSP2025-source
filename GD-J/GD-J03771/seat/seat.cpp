#include<bits/stdc++.h>
 using namespace std;
int n,m,a[105],b,x,y,k=1,mp[15][15];
bool f(int a,int b){
	return a>b;
}
 int main(){
 	freopen("seat.in","r",stdin);
 	freopen("seat.out","w",stdout);

	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	b=a[1];
	sort(a+1,a+n*m+1,f);
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				mp[j][i]=a[k];
				k++;
			}
		}
		else{
			for(int j=m;j>=1;j--){
				mp[j][i]=a[k];
				k++;
			}
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++){
			if(mp[j][i]==b){
				cout<<i<<' '<<j;
				break;
			}
		}
	}
 	fclose(stdin);
 	fclose(stdout);
 	return 0;
 }
