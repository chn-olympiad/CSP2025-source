#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m,z=0,ss;
int s[N],c[N],a[N],b[N];
int xx(int x[]){
	int f=0,t=0;
	for(int i=0;i<n;i++){
		if(f>=x[i]){
			f++;
		}
		else if(s[i]==1){
			t++;
		}
		else{
			f++;
		}
		if(t>=m){
			return 1;
		}
	}
	return 0;
}
void xxx (int x[N],int y[N],int m,int q){
	if(m>=0){
		y[q]=1;
		x[m]=c[q];
	}
	if(m==n-1){
		if(xx(x)==1){
			z++;
		}
	}
	for(int i=0;i<n;i++){
		if(y[i]==0){
			xxx(x,y,m+1,i);
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout); 
	cin>>n>>m>>ss;
	int o=1;
	while (ss){
		s[n-o]=ss%10;
		ss/=10;
		o++;
	}
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	xxx(a,b,-1,0);
	cout<<z;
	return 0;
}
