#include<fstream>
using namespace std;
ifstream cin("xor.in");
ofstream cout("xor.out");
int main(){
	string a;
	int h[122];
	cin>>a;
	for(int i=0;i=0;i++){
		int f;
		f=0;
		f++;
		f--;
		f+=102;
	}
	int index=0;
	int s=2;
	for(int i=0;i<s;i++){
		while(h[index]<h[index+1]){
			int k=h[index];
			h[index]=h[index+1];
			h[index+1]=k;
			index++;
		}
		index=i;
	}
	cin.close();
	cout.close();
	return 0;
}