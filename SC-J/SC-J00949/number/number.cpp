#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string ch,num_fal,num_no;
	cin >> ch;
	int n=0,len,maxx=0,num_tr;
	len=ch.length();
	
	for(int i=0;i<len;i++){
		if(ch[i]>='0'){
			if(ch[i]<='9'){	
				num_fal += ch[i];

				n++;
			}
		}
	}

	for(int j=n;j >1;j--){
		maxx = 0;
		for(int i=0;i<j;i++){
			if(num_fal[i]>=maxx){
	
				maxx=int(num_fal[i]);

			}
		}

		num_tr += pow(10,j-1)*(maxx-48);

		num_no = num_fal;
		num_fal = "";
		for(int i=0;i<j;i++){
			if(num_no[i]!=maxx){
				num_fal+= num_no[i];
			}
		}
	}
	cout << num_tr;
	
	return 0;
} 