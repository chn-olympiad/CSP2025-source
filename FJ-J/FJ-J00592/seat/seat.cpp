#include<bits/stdc++.h>
using namespace std;
long long n,m,r,b,x,y;
bool v[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>m>>n;
	cin>>r;
	v[r]=1;
	for(long long i=2;i<=n*m;i++){
		cin>>b;
		v[b]=1;
	}
	b=1;
	for(long long i=100;i>0;i--){
		if(v[i]){
			if(i==r){
				break;
			}else{
				b++;
			}
		}
	}
	for(long long i=1;i<=n;i++){
		if(b>=((i-1)*m+1)&&b<=i*m){
			x=i;
			break;
		}
	}
	y=b%m;
	if(y==0){
		y=m;
	}
	if(x%2==0){
		y=(m+1)-y;
	}
	cout<<x<<" "<<y;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
