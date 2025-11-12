#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],b,k;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	b=a[0];
	sort(a,a+n*m,cmp);
	for(int i=0;i<n*m;i++){
		if(a[i]==b){
			k=i;
			break;
		}
	}
	cout<<k/n+1<<" ";
	if((k/n)%2==0){
		cout<<k%n+1<<endl;
	}
	else{
		cout<<n-k%n<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
