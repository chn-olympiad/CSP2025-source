#include<bits/stdc++.h>
using namespace std;
int s[110];

bool cmp(int a,int b){
	return a>b;
}

/*
 * 1.ji lu cheng ji
 * 2.pai xu
 * 3.mo ni zuo biao zhao wei zhi
 */
int main(){//T2 2025/11/01 10:33:14 passed.(100 pts)
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>s[i];
	int r=s[1];
	
	sort(s+1,s+n*m+1,cmp);
	int st=1,p=1,x=1,y=1;
	while(s[p]!=r)p++;
	for(int i=1;i<=p-1;i++){
		if((y+st)>n||(y+st)<1){
			x++;
			st=-st;
		}else{
			y+=st;
		}
	}
	cout<<x<<' '<<y<<endl;
	return 0;
}
/*
 * I love playing ADOFAI,espcialy the DLC.
 * I can't stop to tapping my desk.(And my desk is shaking...)
 * I also like Plum's songs,it makes me feel relax.R and daxuehua(Oh no,I forgot its name)is my favourite.
 * Very relax.
 * Very very relax.
 * 
 * 
 * AAAAAAAAAAAAAAAAAAAnd,what about you?
 */
