#include<bits/stdc++.h>
using namespace std;
int a,b,ans,m=0,pai=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&a,&b);
	scanf("%d",&m);
	for(int i=2;i<=a*b;i++){
		int x;
		scanf("%d",&x);
		if(x>m) pai++;
	}
	int lie=(pai-1)/a+1;
	int hang=(lie%2==1)?((pai-1)%a+1):(a-((pai-1)%a+1)+1);
	printf("%d %d",lie,hang);
}
	
