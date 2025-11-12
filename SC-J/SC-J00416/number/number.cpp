#include<bits/c++io.h>
using namespace std;
int main(){
	int a,b[15],n;
	cin>>a;
	for(int i= 0;i<=len(a);i++){
		if(a[i]== '0'){
			b[0]++;
		}
		if(a[i]== '1'){
			b[1]++;
		}
		if(a[i]== '2'){
			b[2]++;
		}
		if(a[i]== '3'){
			b[3]++;
		}
		if(a[i]== '4'){
			b[4]++;
		}
		if(a[i]== '5'){
			b[5]++;
		}
		if(a[i]== '6'){
			b[6]++;
		}
		if(a[i]== '7'){
			b[7]++;
		}
		if(a[i]== '8'){
			b[8]++;
		}
		if(a[i]== '9'){
			b[9]++;
		}
	}
	for(int k=0;k<=len(a);k++){
		if(b[9]>0){
			n+'9';
			b[9]--;
		}
		elif(b[8]>0){
			n+'8';
			b[8]--;
		}
		elif(b[7]>0){
			n+'7';
			b[7]--;
		}
		elif(b[6]>0){
			n+'6';
			b[6]--;
		}
		elif(b[5]>0){
			n+'5';
			b[5]--;
		}
		elif(b[4]>0){
			n+'4';
			b[4]--;
		}
		elif(b[3]>0){
			n+'3';
			b[3]--;
		}
		elif(b[2]>0){
			n+'2';
			b[2]--;
		}
		elif(b[1]>0){
			n+'1';
			b[1]--;
		}
		elif(b[0]>0){
			n+'0';
			b[0]--;
		}
	}
	cout<<n;
	return 0;
}