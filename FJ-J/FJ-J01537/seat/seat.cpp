#include <bits/stdc++.h>
using namespace std;
int a[1000];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int cnt=n*m;
	for(int i=1;i<=cnt;i++){
		cin>>a[i];
	}
	int R=a[1],w;
	sort(a+1,a+1+cnt,cmp);
	for(int i=1;i<=cnt;i++){
		if(a[i]==R){
			w=i;
			break;
		}
	}
	int h,l=0;
//	cout<<w<<endl;
	for(int i=1;i<=cnt;i++){
		if(i%n==0){
			l++;
			if(l*n>=w) break;
		}
	}
//	cout<<l;
	if(l%2==1) h=w-(l-1)*m;
	else{
		h=m+1-(w-(l-1)*m); 
	}
	cout<<l<<" "<<h;
	//n->m
	return 0;
} 
