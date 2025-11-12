#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
LL a[15];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	LL n,m;
	cin>>n>>m;
	for(LL i=1;i<=n*m;i++){
		cin>>a[i];
	}
	LL k=a[1];
	LL p;
	sort(a+1,a+n*m+1);
	for(LL i=1;i<=n*m;i++){
		if(a[i]==k){
			p=i;
		}
	}
	LL t=1,h=1,l=1;
	while(t!=n*m+1-p){
		t++;
		if(l%2==1&&h<=n-1)h++;
		else if(l%2==1&&h==n)l++;
		else if(l%2==0&&h>=2)h--;
		else if(l%2==0&&h==1)l++;
		
	}
	cout<<l<<" "<<h;
	return 0;
}
