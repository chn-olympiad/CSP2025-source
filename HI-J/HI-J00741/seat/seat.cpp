#include<bits/stdc++.h>
using namespace std;
bool com(int a,int b){
	if(a<b) return 0;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,len,cheng,hang,lie,w;
	cin>>n>>m;
	len=n*m;
	int l[len];
	for(int i=0;i<len;i++){
		cin>>l[i];
	}
	cheng=l[0];
	sort(l,l+len,com);
	for(int i=0;i<len;i++){
		if(l[i]==cheng) w=i;
	}
	
	lie=(w-w%n)/n+1;
	
	if(lie%2==1){
		hang=w%n+1;
	}
	if(lie%2==0){
		hang=n-w%n;
	}
	cout<<lie<<" "<<hang;
	return 0;
} 
