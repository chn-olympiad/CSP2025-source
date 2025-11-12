#include <bits/stdc++.h>
using namespace std;
struct f{
	int cj;
	int lie;
	int hang;
	string name;
};
bool t(f a,f b){
	return a.cj>b.cj;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int map1;
	f a[110];
	for(int i=1;i<=n*m;i++){
		cin>>a[i].cj;
		a[i].name="-1";
	}
	a[1].name="小明"; 
	sort(a+1,a+1+n*m,t);
	for(int i=1;i<=n*m;i++){
		if(i%n==0){
			a[i].lie=i/n;
			if((i/n)%2==0){
				a[i].hang=1;
			}
			else{
				a[i].hang=n;
			}
				
		}
		else{
			a[i].lie=i/n+1;
			if((i/n+1)%2==0){
				a[i].hang=1+n-(i%n);
			}
			else{
				a[i].hang=i%n;
			}
		}
	}
	for(int i=1;i<=n*m;i++){
		if(a[i].name=="小明"){
			cout<<a[i].lie<<" "<<a[i].hang;
		}
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
