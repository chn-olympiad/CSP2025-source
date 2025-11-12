#include<iostream>
#include<algorithm>
using namespace std;
long long n,m,a[105],p,t,x=1,y=1,b[15][15],j=2,c;
bool f1=true,f2=true;
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=m*n;i++){
		cin>>a[i];
		if(a[i]!=i){
			f1=false;
		}
		if(a[i]!=n*m-i+1){
			f2=false;
		}
	}
	if(n==1&&m==1){
		cout<<"1 1";
		return 0;
	}
	p=a[1],t=n*m;
	sort(a+1,a+n*m+1,cmp);
	b[1][1]=a[1];
	c=1;
	if(n==1){
		for(long long i=1;i<=n*m;i++){
			if(a[i]==p){
				cout<<i;
				break;
			}
		}
		cout<<" 1";
		return 0;
	}
	if(m==1){
		cout<<"1 ";
		for(long long i=1;i<=n*m;i++){
			if(a[i]==p){
				cout<<i;
				break;
			}
		}
		return 0;
	}
	if(f1){
		cout<<m<<" "<<n;
		return 0;
	}
	if(f2){
		cout<<"1 1";
		return 0;
	}
	while(t--){
		if(x<n&&!b[x+1][y]&&(c&1)){
			b[x+1][y]=a[j];
			x++;
		}else if(x>1&&!b[x-1][y]&&!(c&1)){
			b[x-1][y]=a[j];
			x--;
		}
		if(x==n||x==1){
			y++;
			c++;
		}
		j++;
	}
	for(long long i=1;i<=n;i++){
		for(long long k=1;k<=m;k++){
			if(b[i][k]==p){
				cout<<k<<" "<<i;
				return 0;
			}
			//cout<<b[i][k]<<" ";
		}
		//cout<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
