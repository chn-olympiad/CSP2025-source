#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
long long n,m,x,y,a[N],c,i=1,j=1,k=1,b[15][15];
string s,s1,s2;
struct No{
	long long h,r;
};
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>a[1];
	c=a[1];
	for(long long i=2;i<=n*m;i++)cin>>a[i];
	sort(a+1,a+n*m+1,cmp);
	for(long long i=1;i<=n*m;i++){
		if(c==a[i]){
			x=i;
			break;
		}
	}
	if(x==1){
		cout<<1<<" "<<1;
		return 0;	
	}
	while(1){
		for(int f=1;f<n;f++){
			k++;
			j++;
			if(k==x){
				cout<<i<<" "<<j;
				return 0;
			}
		}
		k++;
		i++;
		if(k==x){
			cout<<i<<" "<<j;
			return 0;
		}
		for(int f=1;f<n;f++){
			k++;
			j--;
			if(k==x){
				cout<<i<<" "<<j;
				return 0;
			}
		}
		k++;
		i++;
		if(k==x){
			cout<<i<<" "<<j;
			return 0;
		}
	}
	return 0;
}
