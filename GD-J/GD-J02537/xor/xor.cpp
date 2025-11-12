#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int a[50005];
int n,k;
int xo(int a,int b)
{
	int t =max(a,b);
	int s =min(a,b);
	int p = 0,sum = 0;
	while (t>0)
	{
		if(t%2>s%2 || s%2>t%2)
			sum+=pow(2.0,p);
		p++;
		t/=2;
		s/=2;
	}
	return sum;
}
int swipfind(int ab,int al,int bb,int bl)
{
	int as=a[ab],bs=a[bb];
	for(int i = ab+1; i <= al; i++)
		as=xo(as,a[i]);
	for(int i = bb+1; i <= bl; i++)
		bs=xo(bs,a[i]);
	if(as==bs && as==k){
		return max(al-ab+1,bl-bb+1);
	}
	return 0;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
	cin>>n>>k;
	int re;
	for(int i = 1; i <= n; i++)
		cin>>a[i];
	for(int i = 1; i < n-1; i++)
		for(int j = i; j < n-1; j++)
			for(int k = j+1; k <= n; k++)
				for(int o = k; o <= n; o++)
					re=max(re,swipfind(i,j,k,o));
	cout<<re;
	return 0;
}
