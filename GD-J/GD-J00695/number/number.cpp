#include<bits/stdc++.h>
using namespace std;

long long n;
string s,s111="";
int a[10]={0},tt=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(char i:s){
		
		if(i=='1')a[1]++;
		if(i=='2')a[2]++;
		if(i=='3')a[3]++;
		if(i=='4')a[4]++;
		if(i=='5')a[5]++;
		if(i=='6')a[6]++;
		if(i=='7')a[7]++;
		if(i=='8')a[8]++;
		if(i=='9')a[9]++;
		if(i=='0')a[0]++;
	}
	for(int i = 9;i>=0;i--){
		if(a[i]>0){
			for(int j =0;j<a[i];j++){
				s111+=i+'a';
			}
		}
	}
	for(char i:s111){
		if (i=='j'){
			tt*=10;
			tt+=9;
		}
		if (i=='f'){
			tt*=10;
			tt+=5;
		}
		if (i=='e'){
			tt*=10;
			tt+=4;
		}
		if (i=='d'){
			tt*=10;
			tt+=3;
		}
		if (i=='c'){
			tt*=10;
			tt+=2;
		}
		if (i=='b'){
			tt*=10;
			tt+=1;
		}
		if (i=='g'){
			tt*=10;
			tt+=6;
		}
		if (i=='h'){
			tt*=10;
			tt+=7;
		}
		if(i=='i'){
			tt*=10;
			tt+=8;
		}
		
		if(i=='a')tt*=10;
		
}

	cout << tt;
	return 0;
}
