#include<fstream>
using namespace  std;
ifstream cin("number.in");
ofstream cout("number.out");
string a;
int i=0,yy[11]={},a1=0,a2=0,a3=0,a4=0,a5=0,a6=0,a7=0,a8=0,a9=0,a0=0;
int main(){
	cin>>a;
	while(a[i]){
			if(a[i]=='0'){
				yy[0]++;
			}
			if(a[i]=='1'){
				yy[1]++;
			}
			if(a[i]=='2'){
				yy[2]++;
			}
			if(a[i]=='3'){
				yy[3]++;
			}
			if(a[i]=='4'){
				yy[4]++;
			}
			if(a[i]=='5'){
				yy[5]++;
			}
			if(a[i]=='6'){
				yy[6]++;
			}
			if(a[i]=='7'){
				yy[7]++;
			}
			if(a[i]=='8'){
				yy[8]++;
			}
			if(a[i]=='9'){
				yy[9]++;
			}
		i++;
	}
	for(int i=9;i>=1;i--){
		if(yy[i]){
			for(int j=1;j<=yy[i];j++){
				cout<<i;
			}
		}
		
	}
	cin.close();
	cout.close();
	return 0;
}
