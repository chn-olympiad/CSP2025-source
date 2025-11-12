#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m,s[(int)(1e3+10)],r;


int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	scanf("%d %d",&n,&m);
	for(int i=0;i<n*m;i++)
	{
		scanf("%d",&s[i]);
	}
	r=s[0];
	sort(s,s+n*m);
	int p=n*m-(int)(lower_bound(s,s+n*m,r)-s);
	int l=(p-1+n)/n;
	bool bl=l%2?false:true;
//	printf("%d %d\n",p,l);
	printf("%d %d",l,(bl?l*n-p+1:p+n-l*n));
	return 0;
//Ò»¶¨ÒªACÑ½ qwq 
//   ______
//  |//////|
//  |//Í¼//|
//  |//Áé//|
//  |//////|
// //////////  orz orz orz
// orz orz orz orz orz orz orz orz
// orz orz orz orz orz orz orz orz orz orz
// orz orz orz orz orz orz orz orz orz orz orz orz
// orz orz orz orz orz orz orz orz orz orz orz orz orz orz
// orz orz orz orz orz orz orz orz orz orz orz orz orz orz orz orz
}


