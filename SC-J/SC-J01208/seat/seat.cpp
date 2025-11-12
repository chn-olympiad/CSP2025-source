#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(int a,int b){return a>b;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a1;
	cin>>n>>m;
	int a[n*m+1];
	for(int i=1;i<=n*m;++i)cin>>a[i];
	a1=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1,k=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++,k++){
				if(a[k]==a1){
					cout<<i<<' '<<j;
					fclose(stdin);
					fclose(stdout);
					return 0;
				}
			}
		}
		if(i%2==0){
			for(int j=n;j>=1;j--,k++){
				if(a[k]==a1){
					cout<<i<<' '<<j;
					fclose(stdin);
					fclose(stdout);
					return 0;
				}
			}
		}
	}
}