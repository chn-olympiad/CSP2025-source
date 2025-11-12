#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,a[10001],grade,cnt;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	grade=a[1];
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n*m,greater<int>());
	for(int i=1;i<=m;i++){
		if(i%2!=0){
			for(int j=1;j<=n;j++){
				cnt++;
				if(a[cnt]==grade){
					cout<<i<<" "<<j;
					fclose(stdin);
					fclose(stdout);
					return 0;
				}
			}
		}else{
			for(int j=n;j>=1;j--){
				cnt++;
				if(a[cnt]==grade){
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
