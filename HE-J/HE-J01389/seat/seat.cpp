#include<bits/stdc++.h>
using namespace std;
int f(int x,int y){
	return x>y;
}
int main(){
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[101]={};
	int z=n*m;
	for(int i=1;i<=z;i++){
		cin>>a[i];
	}
	int q=a[1];
	int w;
	sort(a+1,a+z+1,f);
	for(int i=1;i<=z;i++){
		if(a[i]==q){
			w=i-1;
			break;
		}
	}
	int p=1,o=1,p1=1;
	while(w!=0){
		if(o%2==0){
			if(p>1){
				p--;
			}else{
				o++;
			}
		}else{
			if(p==n || p==1 && p1!=1){
			o++;
			p1++;
			}else{
				p++;
			}
		}
		w--;
	}
	cout<<o<<" "<<p;
	return 0;
}
