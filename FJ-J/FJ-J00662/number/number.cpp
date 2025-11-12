#include<bits/stdc++.h>
using namespace std;
int arr[1000009];
int main(){
	ifstream fin("number.in");
	ofstream fout("number.out");
	string str;
	fin >> str;
	int l = 0;
	for(int i = 0;i < str.length();i++){
		if(str[i] >= '0' && str[i] <= '9'){
			arr[l] = str[i] - 48;
			l++;
		}
	}
	sort(arr,arr+l);
	for(int i = l - 1;i >= 0;i--){
		fout << arr[i];
	}
	fin.close();
	fout.close();
	return 0;
}
