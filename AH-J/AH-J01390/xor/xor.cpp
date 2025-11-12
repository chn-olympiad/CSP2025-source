#include <iostream>
#include <algorithm>
using namespace std;

int num[100005] = {};
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin >> n >> k;
	for (int i = 1; i <= n;i++)
	{
		cin >> num[i];
	}
	int ttl = 0;
	int temp = 0;
	for (int i = 1 ; i <= n ; i++){
		temp = num[i] ^ temp;
		if(temp == k){
			ttl++;
			temp = 0;
			continue;
		}
		if (temp == 0)
		{
			continue;
		}
		int temp_temp = temp;
		for (int j = 1 ; j < i; j++)
		{
			temp_temp = temp_temp ^ num[j];
			if(temp_temp == k){
				ttl++;
				temp = 0;
				break;
			}
		}
	}
	cout << ttl;
	return 0;
}
