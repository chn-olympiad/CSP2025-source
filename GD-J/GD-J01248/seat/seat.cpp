#include<bits/stdc++.h>
using namespace std;

int l[200];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>l[i];
	}
	int a1=l[1];
	sort(l+1,l+n*m+1,cmp);
	int flag; 
	for(int i=1;i<=n*m;i++){
		if(l[i]==a1){
			flag=i;
			break;
		}
	}
	int hang=(flag+n-1)/n;
	int lie=flag%n;
	cout<<hang<<" ";
	if(hang%2==0){
		if(lie==0){
			cout<<1;
		}
		else{
			cout<<n-lie+1;
		} 
	}
	else{
		if(lie==0){
			cout<<n;
		}
		else{
			cout<<lie;
		}
	}
	
	return 0;
}
