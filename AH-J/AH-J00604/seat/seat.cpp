#include<bits/stdc++.h>
using namespace std;

int n,m,a[100005],id=1,k,num;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	k=a[1];
	for(int i=2;i<=n*m;i++){
		if(k<a[i]){
			id++;
		}
	}
	while(id>0){
		id-=n;
		num++;
	}
	if(num%2==1){
		cout<<num<<' '<<id+n;
	}
	if(num%2==0){
		cout<<num<<' '<<-id+1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
