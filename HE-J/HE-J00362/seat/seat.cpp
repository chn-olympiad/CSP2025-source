#include <bits/stdc++.h>
using namespace std;
int arr[105];
bool cmp(int a,int b){
	return a > b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,people,bro_r;
	cin>>n>>m;
	people = m*n;
	for(int i = 1;i<=people;i++){
		cin>>arr[i];
	}
	bro_r = arr[1];
	sort(arr+1,arr+people+1,cmp);
	for(int i = 1;i<=people;i++){
		if(arr[i] == bro_r){
			bro_r = i;
			break;
		}
	}
	//int q = bro_r/m;
	int lie;
	if(bro_r%m == 0){
		lie = int(bro_r/m);
		cout<<int(bro_r/m)<<' ';
	}
	else{
		lie = bro_r/m+1;
		cout<<bro_r/m+1<<' ';
	}
	if(lie%2 == 1){
		if(bro_r%n == 0){
			cout<<n<<endl;
		}
		else{
			cout<<bro_r%n<<endl;
		}
	}
	else {
		cout<<n+1-(bro_r%n)<<endl;
	}
	return 0;
}
