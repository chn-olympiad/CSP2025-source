#include<iostream>
#include<algorithm>
using namespace std;
int n,m,a[1005],x,it=0;
bool cmp(int x,int y){
	if(x>y)return 1;
	else return 0;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	x=a[1]; 
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			it++;
			if(a[it]==x){
				if(i%2==1){
					cout<<i<<' '<<j;
					break;
				}else{
					cout<<i<<' '<<n-j+1;
					break;
				}
			}
		}
	}
	return 0;
} 
