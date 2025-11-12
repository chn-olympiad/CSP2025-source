#include<bits/stdc++.h>
using namespace std;
int n,m,b,k,a[105];
int x,i,j=1;
char q='x';
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
		scanf("%d",&a[i]);
	b=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
		if(a[i]==b)
			k=i;
	while(x<k){
		if(q=='x'){
			if(i==n)
				j++,q='s';
			else
				i++;
		}else{
			if(i==1)
				j++,q='x';
			else
				i--;
		}
		x++;
	}
	cout<<j<<" "<<i;
	return 0;
}
//ÎØÎØÎØÎÒºÃ²Ë 
//Äã¹ÈID:1363135 
//stO CCF Orz
