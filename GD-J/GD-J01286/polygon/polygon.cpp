#include<bits/stdc++.h>
using namespace std;int n;
int a[5010],p=0,h;
bool s[5010];
bool sa(int f,int g){
	return f>g;
}
int dd(int y,int u,int e){
	a[e]=1;bool h=0;
	if(u>=3&&y>=h){
		return 1;
		p++;
	}
	for(int i=e+1;i<n;i++){
		int l;
		if(!a[e])l=dd(y+a[e],u+1,i);
		if(l){
			h=1;
		}
	}
	if(h=1){
		return 1; 
	}
	else{
		a[e]=0;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,sa);
	for(int i=0;i<n;i++){
		h=a[i]*2;
		dd(a[i],1,i);
	} 
	cout<<p%998%244%353;
}
