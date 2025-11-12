#include<bits/stdc++.h>
using namespace std;
string a;
int len=0,b[1000010],j=1;
bool cmp(int a,int b){
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin >> a;
	len = a.size();
	for(int i=0;i<len;i++){
		if( a[i] >= '0' && a[i] <= '9' ){
			b[j] = a[i] - '0';
			j++;
		}
	}
	j--;
	sort(b+1,b+1+j,cmp);
	for(int i=1;i<=j;i++){
		cout << b[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
