#include<bits/stdc++.h>
using namespace std;
int n,m;
void check(int n1,int m1,int s){
	if(s==0){
		cout<<m1<<' '<<n1;
		return;
	}
	if(m1%2==1&&n1+1>n){
		m1++;
		check(n1,m1,s-1);
		return;
	}else if(m1%2==0&&n1-1<1){
		m1++;
		check(n1,m1,s-1);
		return;
	}
	if(m1%2==1){
		n1++;
		check(n1,m1,s-1);
		return;
	}else {
		n1--;
		check(n1,m1,s-1);
		return;
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int s;
	cin>>n>>m;
	int v=n*m,a[v],r;
	for(int i=0;i<v;i++){
		cin>>a[i];
		if(i==0) r=a[i];
	}
	for(int i=0;i<v-1;i++){
		for(int z=i+1;z<v;z++){
			if(a[i]<a[z])
				swap(a[i],a[z]);
		}
	}
	for(int i=0;i<v;i++){
		if(r==a[i]){
			s=i+1;
			break;
		}
	}
	check(1,1,s-1);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
