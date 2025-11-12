#include<bits/stdc++.h>
using namespace std;
int n=0,m=0,targ=0,tmp=1;
int a[510],b[510];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		cin >> a[i];
	}
	targ=a[1];
	sort(a+1,a+n*m+1,cmp);
	int i=1,j=1;
	while(i<=m){
		if(j>n){
			i++,j--;
		}
		else if (j<1){
			i++,j++;
		}
		if(a[tmp]==targ){
			cout << i << " " << j;
			fclose(stdin);
			fclose(stdout);
			return 0;
		}
		else if(i%2==1) j++;
		else if(i%2==0) j--;
		tmp++;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}