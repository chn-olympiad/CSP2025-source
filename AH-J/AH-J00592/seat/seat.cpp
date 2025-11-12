#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    int s[n*m],len=n*m,user,id=0,c,r;
    for(int i=0;i<len;i++){
	    scanf("%d",&s[i]);	
	}
	user=s[0];
	sort(s,s+len,greater<int>());
	while(s[id++]!=user);// find out the seat
	if(id%n==0){
	    c=id/n;	
	}else{
	    c=id/n+1;	
	}
	if(c%2==0){
		r=n-(id-n*(c-1))+1;
	}else{
		r=id-n*(c-1);
	}
	printf("%d %d",c,r);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
