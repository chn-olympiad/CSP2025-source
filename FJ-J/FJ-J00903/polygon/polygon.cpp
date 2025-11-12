#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int l;
	cin >> l;
	int a[l+1];
	int s=0;
	for(int i=0;i<l;i++){
		cin >> a[i];
	}
	sort(a+0,a+0+l);
	for(int i=0;i<l;i++){
		for(int j=2;j<l;j++){
			int n=0;
			for(int t=i;t<=j;t++){
				n=n+a[i];
			}
			if(n>2*a[j]){
				s++;
			}
		}
	}
    if(l>3){
    	cout << 0;
	}else{
		cout << s;
	}
}
