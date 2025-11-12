#include<bits/stdc++.h>
using namespace std;
int ac[105];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,k;
	cin >>n>>m;
	for(int i=1;i<=(n*m);i++) cin >>ac[i];
	k=ac[1];
	sort(ac+1,ac+(n*m)+1,cmp);
	int a=0,b=1,c=1;
	for(int i=1;i<=(n*m);i++){
		a+=c;
		if(a>n){
			c=-1;
			a--;
			b++;
		}
		if(a<1){
			c=1;
			a++;
			b++;
		}
		if(ac[i]==k){
			cout <<b<<' '<<a;
			break;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}