#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int n,m;
int a[105];
int o;
int c=0;
bool f;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	o=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		c++;
		if(a[i]==o){
			break;
		}
	}
	cout<<(c-1)/n+1<<" ";
	if(((c-1)/n+1)%2==1){
		cout<<c-n*((c-1)/n);
	}
	else{
		cout<<n-(c-n*((c-1)/n))+1;
	}
	return 0;
} 
