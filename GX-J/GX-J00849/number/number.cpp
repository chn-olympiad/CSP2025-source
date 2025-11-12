#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b)
{
    return a<b;
}


int main(){
	cin.tie(0);
	cout.tie(0);
	freopen("number1.in","r",stdin);
	freopen("number.out","w",stdout);

	char s[1000010];
	int a[1000010];

	int p = 1;
	int k = 1;

	while (cin >> s[p++])

	for (int i = 1; i < p-1; i++)
	{
	    if (s[i]>='0' && s[i]<='9'){
	    	a[k++] = int(s[i]-48);
	    }
	}
	sort(a,a+p-2,cmp);
	int ans=0;
	for (int i = 1; i < k; i++)
        cout << a[i] << " ";
    //cout << ans;

    return 0;
}
