#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a,b,d,e;
	int c[101];
	cin>>a>>b;
	for(int i = 0;i<a*b;i++){
		
		cin>>c[i];
		if(i == 0) d = c[i];
	}
	for(int i = 0;i<a*b-1;i++){
		for(int j =0;j<a*b-1;j ++){
			int w = c[j],y = c[j+1];
			c[j] = max(w,y);
			c[j+1] = min(w,y);
		}
	}
	for(int i = 0;i<a*b;i++){
		if(c[i] == d) e = i+1;
	}
	int f = e/a,s;
	if(e%a!=0){
		f++;
	}
	if(f%2 != 0){
		s = e%a;
	}else{
		if(a%2 == 0){
			s = a/2+(a/2)+1-e%a;
		} else(){
			s = a/2+1+((a/2)+1)-(e%a);
			}
	cout<<f<<' '<<s;
	return 0;
}

