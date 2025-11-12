#include<iostream>
#include<algorithm>
using namespace std;
int n,m,hang,lie,pos,xxx;
int a[100005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1){
			xxx=a[i];
		}
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==xxx){
			//cout<<xxx<<" "<<pos;
			pos=i;
			break;
		}
	}
	lie=pos/n;
	if(pos%n==0){
		lie=pos/n;
	}else{
		lie++;
	}
	if(lie%2==0){
		if(pos%n==0){
			hang=1;
		}else{
			hang=n-(pos%n)+1;
		}
	}else{
		if(pos%n==0){
			hang=n;
		}else{
			hang=pos%n;
		}
	}
	cout<<hang<<" "<<lie;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
