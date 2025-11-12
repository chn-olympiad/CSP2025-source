#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m;
struct awa{
	int num;
	int id;
}a[105];
bool cmp(awa x,awa y){
	return x.num>y.num;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].num;
		a[i].id=i;
	}
	sort(a+1,a+1+n*m,cmp);
	int num=0;
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1){
			num=i;
			break;
		}
	}
	for(int i=0,j=1,k=1;;k++){
		if(j%2!=0){
			i++;
		}
		else{
			i--;
		}
		if(i>n){
			i--;
			j++;
		}
		else if(i<1){
			i++;
			j++;
		}
		if(k==num){
			cout<<j<<" "<<i;
			break;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
