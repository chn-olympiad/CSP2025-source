#include <bits/stdc++.h>
using namespace std;
int n,m,a[110],now,id;
bool cmp(int a,int b){
	return a > b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n*m;i++){
		cin>>a[i];
		if(i == 1){
			now = a[1];
		}
	}
	sort(a+1,a+1+(n*m),cmp);
	for(int i = 1;i<=n*m;i++){
		if(a[i] == now){
			id = i;
			break;
		}
	}
	int cnt = 0;
	for(int i = 1;i<=m;i++){
		if(i % 2 == 1){
			for(int j = 1;j<=n;j++){
				cnt++;
				if(cnt == id){
					cout<<i<<" "<<j;
					fclose(stdin);
					fclose(stdout);
					return 0;
				}
			}
		}
		else{
			for(int j = n;j>=1;j--){
				cnt++;
				if(cnt == id){
					cout<<i<<" "<<j;
					fclose(stdin);
					fclose(stdout);
					return 0;
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//fucking CCF
