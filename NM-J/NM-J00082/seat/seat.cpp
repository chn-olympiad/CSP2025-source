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
	int a[n*m];
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int r=a[0];
	int list;
	sort(a,a+(n*m),cmp);
	for(int i=0;i<n*m;i++){
		if(r==a[i]){
			list=i+1;
		}
	}
	if(list%n==0){
		if((list/n)%2==0){
			cout<<list/n<<" "<<1<<endl;
		}else{
			cout<<list/n<<" "<<n<<endl;
		}
	}else{
		if(list/n==0){
			cout<<1<<" "<<n<<endl;
		}else if((list/n)%2==0){
			cout<<list/n+1<<" "<<list%n<<endl;
		}else{
			cout<<list/n+1<<" "<<n+1-list%n<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
