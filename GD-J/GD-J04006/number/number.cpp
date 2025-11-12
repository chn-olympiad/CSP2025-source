#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string n,a;
	int maxn=-1;
	cin>>n;
	for(int i=0;i<n.length();i++){
		if (n[i]>='0'&&n[i]<='9'){
             n[i]=int(n[i]);
             a += n[i];
	    }
    }
    for (int i = 0;i < a.length();i++)
    {
    	if (a[i] > maxn)
    	{
			a[0] = a[i];
    		maxn = a[i];
    		maxn = a[0];
		}
	}
	cout << a;
	return 0;
}
