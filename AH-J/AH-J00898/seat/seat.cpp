#include <bits/stdc++.h>
using namespace std;
float s[110],r;
int n,m;
bool cmp(float a,float b){return a>b;}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d %d",&n,&m);
    for(int i=1; i<=n*m; i++) scanf("%f",&s[i]);
    r=s[1];
	sort(s+1,s+1+n*m,cmp);
	for(int i=1; i<=n*m; i++){
		if(s[i]==r){
		    int line,row;
		    line=i/n+(i%n==0 ? 0 : 1);
		    row=(line%2==0 ? n-((i-1)%n+1)+1 :(i-1)%n+1);
		    printf("%d %d",line,row);
		    break;
		}
	}
	return 0;
}
