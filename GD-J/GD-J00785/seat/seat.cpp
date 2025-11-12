#include<bits/stdc++.h>
using namespace std;
int a,n,m,fron=1;
bool s[1000];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%d",&a);
	s[a]=true;
	for(int i=1,d;i<n*m;i++){
		scanf("%d",&d);
		s[d]=true;
	}
	for(int i=100;i>a;i--) if(s[i]) fron++;
	if(fron%n){
		int li=fron/n+1;
		printf("%d ",li);
		if(li&1) printf("%d",fron%n);
		else printf("%d",n-fron%n+1);
		return 0;
	}
	printf("%d ",fron/n);
	if(fron/n&1) printf("%d",n);
	else printf("1");
	return 0;
}
