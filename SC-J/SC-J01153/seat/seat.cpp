#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(int a,int b){
	return a > b;
}
int main(){
	freopen("seat.in","w",stdin);
	freopen("seat.out","r",stdout);
	int n,m;
	cin>>n>>m;
	int a[110];
	for(int i = 0;i < n * m;i++)
		cin>>a[i];
	int bz = a[0];
	sort(a,a + n * m,cmp);
	int x = 0;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			if(a[x] == bz){
				cout<<i + 1<<" "<<j + 1;
				return 0; 
			}
			x++;
		}
		i++;
		for(int j = m - 1;j >= 0;j--){
			if(a[x] == bz){
				cout<<i + 1<<" "<<j + 1;
				return 0; 
			}
			x++;
		}
	}
}