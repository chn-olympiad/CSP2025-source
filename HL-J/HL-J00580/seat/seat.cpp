#include<fstream>
using namespace std;
ifstream cin("seat.in");
ofstream cout("seat.out");
int main(){
	int p;
	cin>>p;
	cout<<p;
	cin.close();
	cout.close();
	return 0;
}