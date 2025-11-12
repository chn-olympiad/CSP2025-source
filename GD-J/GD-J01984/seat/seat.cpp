#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
bool cmp(int x,int y){
	return x>y;
}
int k;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
    	cin>>a[i];
	}
	k=a[1];
	int p=1,q=1;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==k){
			k=i;
			break;
		}
	}
	for(int i=1;i<=k-1;i++){
		if(p%2==1){
			q++;
			if(q>n){
				p++;
				q=n;
			}
		}
		else if(p%2==0){
			q--;
			if(q<1){
				p++;
				q=1;
			}
		}
	}
	cout<<p<<' '<<q;
	return 0;
}
