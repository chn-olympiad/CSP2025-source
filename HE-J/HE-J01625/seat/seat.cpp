#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,a[200],b,x,r,c;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	int s=n*m;
	for(int i=1;i<=s;++i){
		scanf("%d",&a[i]);
	}
	b=a[1];
	sort(a+1,a+1+s,cmp);
	r=0,c=1; 
	for(int i=1;i<=s;++i){
		if(c%2==0){
			if(r==1){
				c++;
			}
			else{
				r--;
			}
		}
		else{
			if(r==n){
				c++;
			}
			else{
				r++;
			}
		}
		if(a[i]==b){
			printf("%d %d",c,r);
			break;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
