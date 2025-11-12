#include<bits/stdc++.h>
using namespace std;
int m[5010];
int b[5010];
int num=0;
int n;
int z=0,y=0;
int a;
void p(int x){
	if (x == 0){
		return;
	}
	x--;
	for(int i= 1;i<=n;i++){
		bool flag =true;
		for(int j =0;j<x;j++){
			if (m[i]==m[j]) flag =false;
			}
		if (flag){
			y += m[i];
			if (m[i]>z) z = m[i];
			p(x);
			if (y>z*2 && x == a) {
		    num++;
			}
		}
	}
}
int main(){
	cin>>n;
	freopen ("polygon.ans","r",stdin);
	freopen ("polygon.in","w",stdout);
	for(int i=1;i<=n;i++){
		cin>>m[i];
	}
	for(int i=3;i<=n;i++){
		a = i;
		a--;
		p(i);
	}
	cout<<num;
	return 0;
} 
