#include<bits/stdc++.h>
using namespace std;
int n,m,len,ls,w,h,l,lb[1006];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	
	cin>>n>>m;
	len=n*m;
	for(int i=1;i<=len;i++) cin>>lb[i];
	ls=lb[1];
	
	for(int i=1;i<=len;i++) 
		for(int j=1;j<=len;j++)
			if (lb[i]>lb[j]) swap(lb[i],lb[j]);
			 
	for(int i=1;i<=len;i++) 
		if (lb[i]==ls){
			w=i;
			break;
		}
	
	h=(w+n-1)/m;
	if (h%2==0) l=n-(w%m)+1;
	else l=(w-1)%m+1; 
	
	cout<<h<<" "<<l<<endl; 
	return 0;
} 
