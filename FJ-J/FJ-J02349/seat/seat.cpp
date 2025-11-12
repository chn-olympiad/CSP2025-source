#include<bits/stdc++.h>
using namespace std;
int p[100][100],l[1005],n,m,x;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>l[i];
	}
	x=l[1];
	sort(l+1,l+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(l[i]==x){
			x=i;
			break;
		}
	}
	int q,w;
	if(x%n==0){
		q=x/n;
	}
	else{
		q=x/n+1;
	}
	if(q%2){
		if(x%n==0){
			w=n;
		}
		else{
			w=x%n;
		}
	}
	else{
		if(x%n==0){
			w=1;
		}
		else{
			w=n-x%n+1;
		}
	}
	cout<<q<<' '<<w;
	return 0;
} 
