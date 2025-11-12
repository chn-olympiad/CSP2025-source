#include<bits/stdc++.h>
using namespace std;
long long n,m,x,s,y=1;
long long a[110],cnt;
long long b[110][110];
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>s;
			a[++cnt]=s;
			b[i][j]=a[j];
		}
	}
	x=a[1];
	sort(a+1,a+1+cnt,cmp);
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				b[i][j]=a[y++];
				if(b[i][j]==x){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}else{
			for(int j=m;j>=1;j--){
				b[i][j]=a[y++];
				if(b[i][j]==x){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
