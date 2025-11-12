#include<bits/stdc++.h>
using namespace std;

int n, k, a[500005], sum;

int main() {
	freopen("xor.in","r", stdin);
    freopen("xor.out","w",stdout);
	
	cin >> n >> k;
	for(int i=0; i<n; i++)
	{
		cin >> a[i];
	}
	
	int i=0, j=0;
	
	for(; i<n; i++)
	{
		int t = a[i];
		if(a[i] == k)
		{
			sum++;
			j++;
		}
		else
		{
			for(j = i+1; j<n; j++)
			{
				t^=a[j];
				if(t == k){
					sum++;
					i = j;
					break;
				}
			}
		}
	}
	cout << sum;
	return 0;
} 