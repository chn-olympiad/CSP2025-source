#include<bits/stdc++.h>
using namespace std;
int main(){
	char a[10]={'1','2','3','4','5','6','7','8','9'};
	int n[1000];
	int b[1000]
	for(int i=1;i<=10;i++){
        cin >> n[i];
	}
	for(int i=1;i<=10;i++){
		for(int j=1;j<=9;j++){
			if(n[i]==a[j]){
				b[i]=j;
				sort(b+n+1,b+1);
				cout << b;
			}
		}
	}



	return 0;
}
