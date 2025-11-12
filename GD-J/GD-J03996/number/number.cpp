#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen('number.in','r',stdin); 
	freopen('number.out','w',stdout);
	int a[1000005] = {0},j=0,c;
	string n;
	cin >> n;
	for(int i=0;i<n.size();i++){
		if (n[i] == '1' || n[i] == '2' || n[i] == '3' || n[i] == '4' || n[i] == '5' || n[i] == '6' || n[i] == '7' || n[i] == '8' || n[i] == '9' || n[i] == '0'){
			a[j] = int(n[i])-48;
			j++;
		}
	}
	for(int i=0;i<j;i++){
		for (int k=i;k<j;k++){
			if (a[i] < a[k]){
				c = a[i];
				a[i] = a[k];
				a[k] = c;
			}
			
		}
	}
	for(int i=0;i<j;i++){
		cout << a[i];
	}
	return 0;
}
