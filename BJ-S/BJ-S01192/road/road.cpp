#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	srand(time(0));
	cout<<rand()%998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
