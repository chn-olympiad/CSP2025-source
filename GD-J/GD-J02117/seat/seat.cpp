#include <bits/stdc++.h>
using namespace std;
int score[105];
bool r(int x,int y){
	return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int all=n*m;
    for(int i=1;i<=all;i++){
    	scanf("%d",score+i);
	}
	int f=score[1];
	int ans,ansi,ansj;
	sort(score+1,score+1+all,r);
	for(int i=1;i<=all;i++){
		if(f==score[i]){
			ans=i;
			break;
		}
	}
//	cout<<ans<<"\n";
	if(ans%n==0)ansj=ans/n;
	else ansj=ans/n+1;
//	cout<<ansj<<"\n";
	if(ans%n==0){
		if(ansj%2==0)ansi=n;
		else ansi=1;
	}
	else{
		if(ansj%2==0)ansi=n-ans%n+1;
		else ansi=ans%n;
	}
	
	printf("%d %d",ansj,ansi);
	return 0;
}

