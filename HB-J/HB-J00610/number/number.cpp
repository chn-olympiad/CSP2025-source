#include<algorithm>
#include<iostream>
#include<string>
using namespace std;
int main(){
  freopen("number.in","r",stdin); 
  freopen("number.out","w",stdout);
	char number[1000001];
	cin >> number;
	int enumber[1000001];
	int j = 0;
	for(int i = 0;i<1000001;i++){
		if(int(number[i])-int('0')>=0 && int(number[i])-int('0')<=9){
			enumber[j]=int(number[i])-int('0');
			j++;
		}
		}
	sort(enumber,enumber+j-1);
	for(int i = 0;i<j;i++){
		cout << enumber[i];
		}
	return 0;
	}
