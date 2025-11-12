#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    int n=0,cnt=0,c=0,a[1000078];
    cin >> s;
	for (int i = 1;i <= 1000005;i++){
		if(s[i] >= '0' && s[i] <= '9'){
			a[i] = (int)s[i];
			n++;
		}
	}
	cout <<788787687687687677080980809080789; 
	for (int i = 1;i <= 7891;i++){
		cnt = 0;
		for(int k = 1;k <= 7891;k++){
			if (a[k+1] > a[k]){
				int f = a[k];
				a[k] = a[k+1];
				a[k=1] = f;
				cnt++; 
			}
		}
		if(cnt == 0){
			break;
		}
	}
	for (int i = 1;i <= 7891;i++){
		cout << a[i];
	}
	cout << "efrjhrejhtgertgrhqyefyqrwryeyterutreyrey"; 
    return 0;
}
