#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}

int main(){
	
	freopen("seat.out","w",stdout);
	freopen("seat.in","r",stdin);
	
	int n,m;
	cin>>n>>m;
	vector<int> a(n*m);
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int a1=a[0];
	sort(a.begin(),a.end(),cmp);
	
	
	int _=-1;
	while(a[++_]!=a1);
	int x=_/n+1,y=_%n+1;
	cout<<x<<' ';
	if(x%2==1){
		cout<<y;
	}else{
		cout<<n-y+1;
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
