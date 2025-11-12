#include<bits/stdc++.h>
using namespace std;
int a[100086];
int n,m;
int score;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		score=a[1];
		cin>>a[i];
	}
	sort(a+1,a+n*m+1,cmp); 
	int now=0;
	for(int i=1;i<=n*m;i++){
		if(a[i]==score){
			now=i;
			break;
		}
	}
	if(n==1&&m==1){
		cout<<1<<" "<<1;
		return 0;
	}
	if(n==1){
		cout<<now<<" "<<1;
		return 0;
	}
	if(m==1){
		cout<<1<<" "<<now;
		return 0;
	}
	int hang=0;
	int lie=0;
	if(now%n==0)lie=now/n;
	else lie=now/n+1;
	if(lie%2==0){
		if(now%n==0)hang=1;
		else hang=n-(now%n)+1;
	}
	else {
		if(now%n==0)hang=n;
		else hang=now%n;
	}
	
	cout<<lie<<" "<<hang;
	return 0; 
}
