#include <bits/stdc++.h>
using namespace std;
const int M = 100001;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int a[M],al = 0;
	cin>>s;
	int l = s.size();
	for(int i = 0;i < M;i++) a[i] = -1;
	for(int i = 0;i < l;i++){
		int b = s[i] - '0';
		if(b >= '0' && b <= '9'){
			a[al] = b;
			al++;
			for(int j = 0;j<al-1;j++){
				if(a[j] < a[j+1]){
					int c = a[j];
					a[j] = a[j+1];
					a[j+1] = c;
				}
			}
		}
	}
	
	for(int i = 0;i < al;i++) cout<<a[i];
	return 0;
} 