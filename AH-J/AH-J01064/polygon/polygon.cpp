#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	srand(time(0));
	cout<<rand()%(2*n);
	fclose(stdin);
	fclose(stdout);
}
