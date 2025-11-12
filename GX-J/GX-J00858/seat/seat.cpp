#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	//scanf("%d%d",&n,&m);
	cin>>n>>m;
	int a[105];//ans=0;
	/*cin>>a[1];
	for(int i=2;i<=n*m;++i){
		scanf("%d",&a[i]);
		if(a[i]>a[1]){
			ans++;
			cout<<"ans"<<":"<<ans;
			
		}
	}
	int d1=ans/m;
	if((d1+1)%2==0){
		int d3=ans-d1*m;
		cout<<d3+1<<" "<<d1+1<<endl;
	}
	if((d1+1)%2==1){
		int d3=ans-d1*m;
		cout<<d3+1<<" "<<d1+1<<endl;
	}*/
	cin>>a[1];
	int k=0;
	for(int i=2;i<=n*m;++i){
		cin>>a[i];
		if(a[i]>a[1]) k++;
	}
	//cout<<k;
	int c=k/n;
	cout<<c+1<<" ";
	if((c+1)%2==0){
		int r=n-(k-(c*n));
		cout<<r<<endl;
	}
	if((c+1)%2==1){
		int r=(k-(c*n))+1;
		cout<<r<<endl;
	}
	return 0;
}

