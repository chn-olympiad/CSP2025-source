#include <bits/stdc++.h>
using namespace std;
int a[105],s;
int n,m;
int i,j;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		cin >> a[i];
	}
	s=a[1];
	sort(a+1,a+1+n*m,greater<int>());
	i=1,j=1;
	int k=1;
	int f=0;
	while(1){
		if(a[k]==s){
			break;
		}
		if(i==n&&f==0){
			j++;
			f=1;
			k++;
		}else if(i==1&&f==1){
			j++;
			f=0;
			k++;
		}else if(f==0){
			i++;
			k++;
		}else if(f==1){
			i--;
			k++;
		}
	} 
	cout << j << ' ' << i;
	return 0;
} 
