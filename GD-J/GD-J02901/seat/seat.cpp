#include<bits/stdc++.h>
using namespace std;
const int N=100;
int n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int k,res=1;
	cin>>k;
	int a;
	for(int i=1;i<n*m;i++){
		scanf("%d",&a);
		if(a>k) res++;
	}
	int sum=0,c,r;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			sum++;
			if(res==sum){
				c=i;
				if(i%2){
					r=j;
				}else{
					r=m-j+1;
				}
				break;
			}
		}
	}
	cout<<c<<" "<<r<<endl;
	return 0;
}
