#include<bits/stdc++.h>
using namespace std;
long long n,m,k,a[1001],cnt; 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	cnt = n*m;
	for(int i=1;i<=cnt;i++){
		cin >> a[i];
	}
	k = a[1];
	sort(a+1,a+1+cnt);
	for(int i=1;i<=cnt;i++){
		if(a[i]==k){
			cnt = n*m-i+1;
			break;
		}
	}
	long long len = (cnt-1)/n;
	cout << len+1 << ' ';
	if((len+1)%2){
		cout << cnt-(len*m);
	}else{
		cout << n-(cnt-(len*m))+1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
