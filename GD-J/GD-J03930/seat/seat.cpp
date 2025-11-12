#include <iostream>
#include <algorithm>
using namespace std;
int a[101];
int n,m;
int ming,idx;
int r,c;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n*m;i++){
		cin>>a[i];
	}
	ming = a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i = 1;i<=n*m;i++){
		if(a[i]==ming){
			idx = i;
			break;
		}
	}
	c = idx/n+1;
	if(c%2!=0){
		r=m-(idx%n+1);
	}else r=idx%n+1;
	cout<<c<<" "<<r;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
