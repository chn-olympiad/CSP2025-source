#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >> n;
	if(n<3){
		cout << 0;
		return 0;
		}else {
	int box[n+1];
	for(int i = 1;i<=n;i++){
		cin >> box[i];
		}
	sort(box,box+n-1);
	int f=0;
	for(int i = 1;i<=n;i++){
		for(int j=i+2;j<=n;j++){
			int z=0;
			for(int k=i;k<=j;k++){
				z+=box[k];
				}
				if(z>=2*box[i]){
				f+=n-j+1;
				break;
				}
			}
		}
	cout << f;
		return 0;
	}
}
