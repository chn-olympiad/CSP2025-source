#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int g=n*m;
	int a[g+5];
	for(int i=1;i<=g;i++) cin>>a[i];
	int agg=a[1];
	sort(a+1,a+g+1,cmp);
	for(int i=1;i<=g;i++){
		if(a[i]==agg){
			agg=i;
			break;
		}
	}
	if(agg%n==0) cout<<agg/n<<" "<<n;
	if(agg%n!=0){
		cout<<agg/n+1<<" ";
		if((agg/n+1)%2==0){
			cout<<n-agg%n+1;
		}else{
			cout<<agg%n;
		}
	} 
	return 0;
}

