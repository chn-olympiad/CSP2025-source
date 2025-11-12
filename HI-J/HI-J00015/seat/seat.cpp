#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n*m];
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int l=1,a1=a[0];
	for(int i=0;i<n*m;i++){
		if(a1<a[i]){
			a1=a[i]; 
			l++;
		}
	}
	
	int u=l/m,p=l%m;
	if(p>0)u+=1; 
	if(u==0){
		cout<<1<<" "<<l;
		return 0;
	} 
	if(p==0){
		if(u%2==0)cout<<u%2<<" "<<1;
		else cout<<u<<" "<<m;
	}
	else{
		if(u%2==0)cout<<u<<" "<<m-p+1;
		else cout<<u<<" "<<p;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
