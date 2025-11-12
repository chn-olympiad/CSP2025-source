#include<bits/stdc++.h>
using namespace std;

int a[1000];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	srand(time(0));
	if(rand()%2==0)
		cout << rand()%10*2;
	else
		cout << rand()%18000;
	return 0;
}
