#include<bits/stdc++.h>
using namespace std;
int n,m,r,k,d,h;
int a[150];
bool cmp(int aa,int bb){
	return aa>bb;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	r=a[1];
	sort(a+1,a+1+(n*m),cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			k=i;
			break;
		}
	}
    d=(k-1)/n+1;
	if(d%2==0){
		h=n-(k%n)+1;
		if(h==n+1){
			h=1;
		}
	}
	else{
		h=k%n;
		if(h==0){
			h=n;
		}
	}
	cout<<d<<' '<<h;
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
