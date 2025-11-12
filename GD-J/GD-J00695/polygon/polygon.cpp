#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n,b[10086],sum=0;
	cin >> n;
	for(int i =0;i<n;i++){
		cin >> b[i];
	} 
	for(int i = 0;i<n;i++){
		for(int  j =0;j<b[i];j++){
			for(int y = j;y<b[i];y++){
				if(b[j]+b[y]>b[i])sum++;
				
			}
		}
	}
	cout << sum;
	return 0;
}
